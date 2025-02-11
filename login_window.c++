#include "login_window.h"
#include "menu_window.h"
#include "ui_login_window.h"
#include "user.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

login_window::login_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_window)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &login_window::onLoginClicked);
}

login_window::~login_window()
{
    delete ui;
}

void login_window::onLoginClicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("amazonka");
    db.setUserName("root");
    db.setPassword("12345");

    if (!db.open()) {
        QMessageBox::critical(this, "Niepowodzenie", "Nie udało się połączyć z bazą danych.");
        return;
    }

    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Proszę wprowadzić login i hasło.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT id, admin FROM Users WHERE username = :username AND password = :password");
    query.bindValue(":username", login);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        int userID = query.value("id").toInt();
        bool isAdmin = query.value("admin").toBool();

        User* user = new User(userID, login, password, isAdmin);

        QMessageBox::information(this, "Sukces", "Zalogowano pomyślnie.");
        accept();

        menu_window* menu = new menu_window(user);
        menu->show();
    } else {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowy login lub hasło.");
    }
}
