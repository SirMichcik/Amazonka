#include "menu_window.h"
#include "biblioteka_window.h"
#include "raport_window.h"
#include "ui_menu_window.h"
#include "edit_window.h"
#include "content.h"
#include "add_window.h"
#include "user.h"
#include "zakup_window.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

menu_window::menu_window(User* user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_window),
    user(*user)
{
    ui->setupUi(this);
    numberOfFilms = count("film");
    numberOfSeries = count("series");
    numberOfBooks = count("book");

    createButtons(user, "film", "Obejrzyj Film", ui->scrollAreaWidgetContents);
    createButtons(user, "series", "Obejrzyj Serial", ui->scrollAreaWidgetContents_2);
    createButtons(user, "book", "Czytaj Książkę", ui->scrollAreaWidgetContents_3);

    if(user->getisAdmin()){
        createButton("Dodaj", QSize(150, 50), QPoint(this->width() - 210, 20), [this]() { add(); });
        createButton("Raport", QSize(150, 50), QPoint(this->width() - 400, 20), [this]() { generate_raport();
        });
    }

    connect(ui->biblioteka, &QPushButton::clicked, this, &menu_window::onBibliotekaClicked);
}

menu_window::~menu_window()
{
    delete ui;
}

void menu_window::createButtons(User* user, const QString& type, const QString& buttonTextPrefix, QWidget* scrollAreaWidget)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QSqlQuery query;
    query.prepare("SELECT title, content_id FROM Content WHERE type = :type");
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

        if (user->getisAdmin()) {
            QPushButton* editButton = new QPushButton("Edytuj", this);
            connect(editButton, &QPushButton::clicked, this, [this, contentTitle]() { edit(contentTitle); });
            contentLayout->addWidget(editButton);
        }

        contentWidget->setLayout(contentLayout);
        mainLayout->addWidget(contentWidget);
    }

    scrollAreaWidget->setLayout(mainLayout);
}

int menu_window::count(QString type)
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

void menu_window::edit(QString title) {
    qDebug() << "Edycja zawartości o tytule " << title;

    QSqlQuery query;
    query.prepare("SELECT content_id, title, type, category, author, release_year, limited_offer FROM Content WHERE title = :title");
    query.bindValue(":title", title);

    if (query.exec() && query.next()) {
        Content content(
            query.value("content_id").toInt(),
            query.value("title").toString(),
            query.value("type").toString(),
            query.value("category").toString(),
            query.value("author").toString(),
            query.value("release_year").toInt(),
            query.value("limited_offer").toBool()
            );

        edit_window *editWin = new edit_window(content);
        editWin->show();
    } else {
        qDebug() << "Błąd pobierania danych z bazy:" << query.lastError().text();
    }
}

void menu_window::createButton(const QString& text, const QSize& size, const QPoint& position, std::function<void()> callback) {
    QPushButton* button = new QPushButton(text, this);
    button->setFixedSize(size);
    button->move(position);

    connect(button, &QPushButton::clicked, this, callback);
}

void menu_window::add(){
    add_window *window = new add_window();
    window->show();
}

void menu_window::generate_raport(){
    raport_window *window = new raport_window();
    window->show();
}

void menu_window::use(User* user, int content_id) {
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
        QMessageBox::information(this, "Oglądanie", "Oglądanie zawartości.");

        QSqlQuery query;
        query.prepare("UPDATE Content SET view_count = view_count + 1 WHERE content_id = :content_id");
        query.bindValue(":content_id", content_id);

        if (!query.exec()) {
            qDebug() << "Błąd aktualizacji view_count:" << query.lastError().text();
        } else {
            qDebug() << "Zaktualizowano licznik wyświetleń dla content_id:" << content_id;
        }
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

void menu_window::onBibliotekaClicked(){
    biblioteka_window* biblioteka = new biblioteka_window(&user);
    biblioteka->show();
    accept();
}
