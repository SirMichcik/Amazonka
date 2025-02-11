/********************************************************************************
** Form generated from reading UI file 'edit_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_WINDOW_H
#define UI_EDIT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_window
{
public:
    QLabel *imageLabel;
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
    QPushButton *deleteButton;

    void setupUi(QWidget *edit_window)
    {
        if (edit_window->objectName().isEmpty())
            edit_window->setObjectName("edit_window");
        edit_window->resize(600, 450);
        imageLabel = new QLabel(edit_window);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(0, 0, 300, 450));
        imageLabel->setScaledContents(true);
        label_title = new QLabel(edit_window);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(350, 20, 200, 30));
        label_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_title_name = new QLabel(edit_window);
        label_title_name->setObjectName("label_title_name");
        label_title_name->setGeometry(QRect(350, 70, 200, 20));
        lineEdit = new QLineEdit(edit_window);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(350, 90, 200, 25));
        label_type = new QLabel(edit_window);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(350, 130, 200, 20));
        lineEdit_2 = new QLineEdit(edit_window);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(350, 150, 200, 25));
        label_category = new QLabel(edit_window);
        label_category->setObjectName("label_category");
        label_category->setGeometry(QRect(350, 190, 200, 20));
        lineEdit_3 = new QLineEdit(edit_window);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(350, 210, 200, 25));
        label_author = new QLabel(edit_window);
        label_author->setObjectName("label_author");
        label_author->setGeometry(QRect(350, 250, 200, 20));
        lineEdit_4 = new QLineEdit(edit_window);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(350, 270, 200, 25));
        label_year = new QLabel(edit_window);
        label_year->setObjectName("label_year");
        label_year->setGeometry(QRect(350, 310, 200, 20));
        lineEdit_5 = new QLineEdit(edit_window);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(350, 330, 200, 25));
        checkBox = new QCheckBox(edit_window);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(350, 370, 200, 20));
        saveButton = new QPushButton(edit_window);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(350, 400, 91, 40));
        deleteButton = new QPushButton(edit_window);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(460, 400, 91, 40));

        retranslateUi(edit_window);

        QMetaObject::connectSlotsByName(edit_window);
    } // setupUi

    void retranslateUi(QWidget *edit_window)
    {
        edit_window->setWindowTitle(QCoreApplication::translate("edit_window", "Okno edycji", nullptr));
        label_title->setText(QCoreApplication::translate("edit_window", "Okno edycji", nullptr));
        label_title_name->setText(QCoreApplication::translate("edit_window", "Tytu\305\202", nullptr));
        label_type->setText(QCoreApplication::translate("edit_window", "Typ", nullptr));
        label_category->setText(QCoreApplication::translate("edit_window", "Kategoria", nullptr));
        label_author->setText(QCoreApplication::translate("edit_window", "Autor", nullptr));
        label_year->setText(QCoreApplication::translate("edit_window", "Rok wydania", nullptr));
        checkBox->setText(QCoreApplication::translate("edit_window", "Oferta specjalna", nullptr));
        saveButton->setText(QCoreApplication::translate("edit_window", "Zapisz", nullptr));
        deleteButton->setText(QCoreApplication::translate("edit_window", "Usu\305\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edit_window: public Ui_edit_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_WINDOW_H
