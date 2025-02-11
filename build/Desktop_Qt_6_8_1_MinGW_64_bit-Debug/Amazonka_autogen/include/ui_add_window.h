/********************************************************************************
** Form generated from reading UI file 'add_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_WINDOW_H
#define UI_ADD_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_add_window
{
public:
    QLabel *label_title;
    QLabel *label_title_name;
    QLineEdit *lineEdit;
    QLabel *label_type;
    QLineEdit *lineEdit_2;
    QLabel *label_category;
    QLineEdit *lineEdit_3;
    QLabel *label_author;
    QLineEdit *lineEdit_4;
    QLabel *label_year;
    QLineEdit *lineEdit_5;
    QCheckBox *checkBox;
    QPushButton *saveButton;

    void setupUi(QDialog *add_window)
    {
        if (add_window->objectName().isEmpty())
            add_window->setObjectName("add_window");
        add_window->resize(600, 450);
        label_title = new QLabel(add_window);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(350, 20, 200, 30));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_title_name = new QLabel(add_window);
        label_title_name->setObjectName("label_title_name");
        label_title_name->setGeometry(QRect(350, 70, 200, 20));
        lineEdit = new QLineEdit(add_window);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(350, 90, 200, 25));
        label_type = new QLabel(add_window);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(350, 130, 200, 20));
        lineEdit_2 = new QLineEdit(add_window);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(350, 150, 200, 25));
        label_category = new QLabel(add_window);
        label_category->setObjectName("label_category");
        label_category->setGeometry(QRect(350, 190, 200, 20));
        lineEdit_3 = new QLineEdit(add_window);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(350, 210, 200, 25));
        label_author = new QLabel(add_window);
        label_author->setObjectName("label_author");
        label_author->setGeometry(QRect(350, 250, 200, 20));
        lineEdit_4 = new QLineEdit(add_window);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(350, 270, 200, 25));
        label_year = new QLabel(add_window);
        label_year->setObjectName("label_year");
        label_year->setGeometry(QRect(350, 310, 200, 20));
        lineEdit_5 = new QLineEdit(add_window);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(350, 330, 200, 25));
        checkBox = new QCheckBox(add_window);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(350, 370, 200, 20));
        saveButton = new QPushButton(add_window);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(350, 400, 200, 40));

        retranslateUi(add_window);

        QMetaObject::connectSlotsByName(add_window);
    } // setupUi

    void retranslateUi(QDialog *add_window)
    {
        add_window->setWindowTitle(QCoreApplication::translate("add_window", "Okno edycji", nullptr));
        label_title->setText(QCoreApplication::translate("add_window", "Okno edycji", nullptr));
        label_title_name->setText(QCoreApplication::translate("add_window", "Tytu\305\202", nullptr));
        label_type->setText(QCoreApplication::translate("add_window", "Typ", nullptr));
        label_category->setText(QCoreApplication::translate("add_window", "Kategoria", nullptr));
        label_author->setText(QCoreApplication::translate("add_window", "Autor", nullptr));
        label_year->setText(QCoreApplication::translate("add_window", "Rok wydania", nullptr));
        checkBox->setText(QCoreApplication::translate("add_window", "Oferta specjalna", nullptr));
        saveButton->setText(QCoreApplication::translate("add_window", "Zapisz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_window: public Ui_add_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_WINDOW_H
