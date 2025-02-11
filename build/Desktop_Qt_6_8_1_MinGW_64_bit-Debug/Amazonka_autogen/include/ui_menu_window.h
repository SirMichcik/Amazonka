/********************************************************************************
** Form generated from reading UI file 'menu_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_WINDOW_H
#define UI_MENU_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_window
{
public:
    QLabel *label_title;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_films;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_series;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_books;
    QPushButton *biblioteka;

    void setupUi(QDialog *menu_window)
    {
        if (menu_window->objectName().isEmpty())
            menu_window->setObjectName("menu_window");
        menu_window->resize(1294, 990);
        label_title = new QLabel(menu_window);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(40, 10, 250, 40));
        QFont font;
        font.setPointSize(35);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        scrollArea = new QScrollArea(menu_window);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(50, 80, 1191, 450));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1189, 448));
        label_films = new QLabel(scrollAreaWidgetContents);
        label_films->setObjectName("label_films");
        label_films->setGeometry(QRect(10, 0, 49, 16));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(menu_window);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(50, 540, 581, 450));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 579, 448));
        label_series = new QLabel(scrollAreaWidgetContents_2);
        label_series->setObjectName("label_series");
        label_series->setGeometry(QRect(10, 0, 49, 16));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea_3 = new QScrollArea(menu_window);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(660, 540, 581, 450));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 579, 448));
        label_books = new QLabel(scrollAreaWidgetContents_3);
        label_books->setObjectName("label_books");
        label_books->setGeometry(QRect(10, 0, 49, 16));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        biblioteka = new QPushButton(menu_window);
        biblioteka->setObjectName("biblioteka");
        biblioteka->setGeometry(QRect(490, 10, 201, 61));
        QFont font1;
        font1.setPointSize(16);
        biblioteka->setFont(font1);

        retranslateUi(menu_window);

        QMetaObject::connectSlotsByName(menu_window);
    } // setupUi

    void retranslateUi(QDialog *menu_window)
    {
        menu_window->setWindowTitle(QCoreApplication::translate("menu_window", "Menu G\305\202\303\263wne", nullptr));
        label_title->setText(QCoreApplication::translate("menu_window", "Amazonka", nullptr));
        label_films->setText(QCoreApplication::translate("menu_window", "Filmy", nullptr));
        label_series->setText(QCoreApplication::translate("menu_window", "Seriale", nullptr));
        label_books->setText(QCoreApplication::translate("menu_window", "Ksi\304\205\305\274ki", nullptr));
        biblioteka->setText(QCoreApplication::translate("menu_window", "Biblioteka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_window: public Ui_menu_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_WINDOW_H
