#include "zakup_window.h"
#include "ui_zakup_window.h"

#include <QDebug>
#include <QMessageBox>

zakup_window::zakup_window(Content content, User user, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::zakup_window)
    , content(content)
    , user(user)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &zakup_window::onSubskrybujClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &zakup_window::onZakupClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &zakup_window::onWypozyczClicked);
}

zakup_window::~zakup_window()
{
    delete ui;
}

void zakup_window::onSubskrybujClicked(){
    qDebug() << "Sub kliknięty";
    zakup.subskrybuj(user);
    QMessageBox::information(this, "Sukces", "Zasubskrybowano całą zawartość.");
    accept();
}

void zakup_window::onZakupClicked() {
    qDebug() << "Zakup kliknięty";
    zakup.kup(content, user);
    QMessageBox::information(this, "Sukces", "Zawartość kupiona.");
    accept();
}

void zakup_window::onWypozyczClicked() {
    qDebug() << "Wypożycz kliknięty";
    zakup.wypozycz(content, user);
    QMessageBox::information(this, "Sukces", "Zawartość wypożyczona.");
    accept();
}
