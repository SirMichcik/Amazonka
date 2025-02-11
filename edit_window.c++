#include "edit_window.h"
#include "ui_edit_window.h"
#include "content.h"

#include <QMessageBox>

edit_window::edit_window(const Content &content, QDialog *parent)
    : QDialog(parent), ui(new Ui::edit_window), content(content) {
    ui->setupUi(this);
    loadContentData();
    loadPicture();
}

edit_window::~edit_window() {
    delete ui;
}

void edit_window::loadContentData() {
    ui->lineEdit->setText(content.getTitle());
    ui->lineEdit_2->setText(content.getType());
    ui->lineEdit_3->setText(content.getCategory());
    ui->lineEdit_4->setText(content.getAuthor());
    ui->lineEdit_5->setText(QString::number(content.getReleaseYear()));
    ui->checkBox->setChecked(content.isLimitedOffer());
}

void edit_window::loadPicture() {
    QString imagePath = "C:/Users/micha/Desktop/Amazonka/resources/" + content.getTitle() + ".jpg";
    QPixmap pixmap(imagePath);

    qDebug() << "imagePath:" << imagePath;

    if (pixmap.isNull()) {
        QMessageBox::warning(this, "Błąd obrazu", "Nie udało się załadować obrazu: " + imagePath);
    } else {
        pixmap = pixmap.scaled(300, 450, Qt::KeepAspectRatio);
        ui->imageLabel->setPixmap(pixmap);  // Ustawienie obrazka w QLabel
    }
}

void edit_window::on_saveButton_clicked()
{
    bool ok;

    content.setTitle(ui->lineEdit->text());
    content.setType(ui->lineEdit_2->text());
    content.setCategory(ui->lineEdit_3->text());
    content.setAuthor(ui->lineEdit_4->text());
    content.setReleaseYear(ui->lineEdit_5->text().toInt(&ok));
    content.setLimitedOffer(ui->checkBox->isChecked());

    content.updateContent();

    QMessageBox::information(this, "Sukces", "Zapisano pomyślnie.");
    accept();
}

void edit_window::on_deleteButton_clicked(){
    content.deleteContent();
    accept();
}
