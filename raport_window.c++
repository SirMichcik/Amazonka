#include "raport_window.h"
#include "ui_raport_window.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

raport_window::raport_window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::raport_window)
{
    ui->setupUi(this);

    connect(ui->typeFilter, &QComboBox::currentTextChanged, this, &raport_window::updateTable);
    updateTable();
}

void raport_window::updateTable() {
    QString selectedType = ui->typeFilter->currentText();
    QString queryString = R"(
        SELECT c.title, c.type, c.view_count,
               (SELECT COUNT(*) FROM UserContent uc WHERE uc.content_id = c.content_id) AS access_count
        FROM Content c
    )";

    if (selectedType != "Wszystkie") {
        queryString += " WHERE c.type = :type";
    }

    QSqlQuery query;
    query.prepare(queryString);

    if (selectedType != "Wszystkie") {
        query.bindValue(":type", selectedType);
    }

    if (!query.exec()) {
        qDebug() << "Błąd pobierania danych:" << query.lastError().text();
        return;
    }

    qDebug() << "Dane z bazy:";
    ui->tableWidget->setRowCount(0);
    int row = 0;

    while (query.next()) {
        QString title = query.value(0).toString();
        QString type = query.value(1).toString();
        int viewCount = query.value(2).toInt();
        int accessCount = query.value(3).toInt();

        qDebug() << title << type << viewCount << accessCount;

        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(title));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(viewCount)));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(accessCount)));
        row++;
    }

    ui->tableWidget->resizeColumnsToContents();
}

raport_window::~raport_window()
{
    delete ui;
}
