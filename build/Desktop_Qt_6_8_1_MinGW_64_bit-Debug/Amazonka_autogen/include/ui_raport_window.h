/********************************************************************************
** Form generated from reading UI file 'raport_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAPORT_WINDOW_H
#define UI_RAPORT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_raport_window
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *typeFilter;
    QTableWidget *tableWidget;

    void setupUi(QWidget *raport_window)
    {
        if (raport_window->objectName().isEmpty())
            raport_window->setObjectName("raport_window");
        raport_window->resize(600, 400);
        verticalLayout = new QVBoxLayout(raport_window);
        verticalLayout->setObjectName("verticalLayout");
        typeFilter = new QComboBox(raport_window);
        typeFilter->addItem(QString());
        typeFilter->addItem(QString());
        typeFilter->addItem(QString());
        typeFilter->addItem(QString());
        typeFilter->setObjectName("typeFilter");
        typeFilter->setEditable(false);

        verticalLayout->addWidget(typeFilter);

        tableWidget = new QTableWidget(raport_window);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setColumnCount(4);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(raport_window);

        QMetaObject::connectSlotsByName(raport_window);
    } // setupUi

    void retranslateUi(QWidget *raport_window)
    {
        raport_window->setWindowTitle(QCoreApplication::translate("raport_window", "Raport", nullptr));
        typeFilter->setItemText(0, QCoreApplication::translate("raport_window", "Wszystkie", nullptr));
        typeFilter->setItemText(1, QCoreApplication::translate("raport_window", "film", nullptr));
        typeFilter->setItemText(2, QCoreApplication::translate("raport_window", "book", nullptr));
        typeFilter->setItemText(3, QCoreApplication::translate("raport_window", "series", nullptr));

        tableWidget->setHorizontalHeaderLabels(QStringList{
            QCoreApplication::translate("raport_window", "Tytu\305\202", nullptr),
            QCoreApplication::translate("raport_window", "Typ", nullptr),
            QCoreApplication::translate("raport_window", "Wy\305\233wietlenia", nullptr),
            QCoreApplication::translate("raport_window", "Dost\304\231py", nullptr)});
    } // retranslateUi

};

namespace Ui {
    class raport_window: public Ui_raport_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAPORT_WINDOW_H
