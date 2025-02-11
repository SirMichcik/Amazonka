#include "add_window.h"
#include "content.h"
#include "ui_add_window.h"

#include <QMessageBox>

add_window::add_window(QDialog *parent)
    : QDialog(parent), ui(new Ui::add_window) {
    ui->setupUi(this);
}

add_window::~add_window() {
    delete ui;
}

void add_window::on_saveButton_clicked() {
    content.setTitle(ui->lineEdit->text());
    content.setType(ui->lineEdit_2->text());
    content.setCategory(ui->lineEdit_3->text());
    content.setAuthor(ui->lineEdit_4->text());
    content.setReleaseYear(ui->lineEdit_5->text().toInt());
    content.setLimitedOffer(ui->checkBox->isChecked());

    content.addContent();

    QMessageBox::information(this, "Sukces", "Dodano nową zawartość.");
    accept();
}
