#include "biblioteka_window.h"
#include "content.h"
#include "menu_window.h"
#include "ui_biblioteka_window.h"
#include "zakup_window.h"
#include <qboxlayout.h>
#include <qmessagebox.h>
#include <qsqlerror.h>
#include <qsqlquery.h>

biblioteka_window::biblioteka_window(User* user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::biblioteka_window)
    , user(*user)
{
    ui->setupUi(this);
    numberOfFilms = count("film");
    numberOfSeries = count("series");
    numberOfBooks = count("book");

    createButtons(user, "film", "Obejrzyj Film", ui->scrollAreaWidgetContents);
    createButtons(user, "series", "Obejrzyj Serial", ui->scrollAreaWidgetContents_2);
    createButtons(user, "book", "Czytaj Książkę", ui->scrollAreaWidgetContents_3);

    connect(ui->menu_button, &QPushButton::clicked, this, &biblioteka_window::onMenuClicked);
}

biblioteka_window::~biblioteka_window()
{
    delete ui;
}

void biblioteka_window::createButtons(User* user, const QString& type, const QString& buttonTextPrefix, QWidget* scrollAreaWidget)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QSqlQuery query;
    query.prepare("SELECT Content.title, Content.content_id "
                  "FROM Content "
                  "JOIN UserContent ON Content.content_id = UserContent.content_id "
                  "WHERE UserContent.user_id = :user_id AND Content.type = :type");
    query.bindValue(":user_id", user->getID());
    query.bindValue(":type", type);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd zapytania", "Nie udało się wykonać zapytania SQL.");
        return;
    }

    int contentIndex = 0;
    while (query.next()) {
        contentIndex++;
        QString contentTitle = query.value("title").toString();
        int content_id = query.value("content_id").toInt();

        QWidget* contentWidget = new QWidget(this);
        QVBoxLayout* contentLayout = new QVBoxLayout;

        QString imagePath = "C:/Users/micha/Desktop/Amazonka/resources/" + contentTitle + ".jpg";
        QPixmap pixmap(imagePath);

        qDebug() << "imagePath:" << imagePath;

        if (pixmap.isNull()) {
            QMessageBox::warning(this, "Błąd obrazu", "Nie udało się załadować obrazu: " + imagePath);
        } else {
            pixmap = pixmap.scaled(200, 300, Qt::KeepAspectRatio);
        }

        QLabel* label = new QLabel(this);
        label->setPixmap(pixmap);

        QPushButton* button = new QPushButton(buttonTextPrefix + " " + contentTitle, this);
        connect(button, &QPushButton::clicked, this, [this, content_id, user]() { use(user, content_id); });

        contentLayout->addWidget(label);
        contentLayout->addWidget(button);

        contentWidget->setLayout(contentLayout);
        mainLayout->addWidget(contentWidget);
    }

    scrollAreaWidget->setLayout(mainLayout);
}

int biblioteka_window::count(QString type)
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isOpen()) {
        QMessageBox::critical(this, "Błąd połączenia", "Nie udało się połączyć z bazą danych.");
        return 0;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Content WHERE type = :type");
    query.bindValue(":type", type);

    int number;
    if (query.exec() && query.next()) {
        number = query.value(0).toInt();
        qDebug() << "Liczba zawartości typu " << type << " w bazie danych: " << number;
        return number;
    } else {
        QMessageBox::critical(this, "Błąd zapytania", "Nie udało się wykonać zapytania SQL.");
        return 0;
    }
}

void biblioteka_window::use(User* user, int content_id) {
    QSqlQuery query;
    query.prepare("SELECT content_id, title, type, category, author, release_year, limited_offer FROM Content WHERE content_id = :content_id");
    query.bindValue(":content_id", content_id);

    Content content;

    if (query.exec() && query.next()) {
        content = Content(
            query.value("content_id").toInt(),
            query.value("title").toString(),
            query.value("type").toString(),
            query.value("category").toString(),
            query.value("author").toString(),
            query.value("release_year").toInt(),
            query.value("limited_offer").toBool()
            );
    } else {
        qDebug() << "Błąd pobierania danych z bazy:" << query.lastError().text();
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać danych o treści.");
        return;
    }

    if (user->check_access(content_id)) {
        qDebug() << "Użytkownik ma dostęp do treści: " << content.getTitle();
        // Kod do otwarcia treści
    } else {
        qDebug() << "Użytkownik nie ma dostępu do treści: " << content.getTitle();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Brak dostępu",
                                      "Nie masz dostępu do \"" + content.getTitle() + "\". Czy chcesz ją zakupić?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            qDebug() << "Użytkownik chce kupić zawartość: " << content.getTitle();
            zakup_window *zakupWin = new zakup_window(content, *user);
            zakupWin->show();
        } else {
            qDebug() << "Użytkownik anulował zakup.";
        }
    }
}

void biblioteka_window::onMenuClicked(){
    menu_window* menu = new menu_window(&user);
    menu->show();
    accept();
}
