/********************************************************************************
** Form generated from reading UI file 'zakup_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZAKUP_WINDOW_H
#define UI_ZAKUP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_zakup_window
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *zakup_window)
    {
        if (zakup_window->objectName().isEmpty())
            zakup_window->setObjectName("zakup_window");
        zakup_window->resize(591, 180);
        pushButton = new QPushButton(zakup_window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 40, 151, 91));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(zakup_window);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 40, 151, 91));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(zakup_window);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(410, 40, 151, 91));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        pushButton_3->setFont(font1);

        retranslateUi(zakup_window);

        QMetaObject::connectSlotsByName(zakup_window);
    } // setupUi

    void retranslateUi(QDialog *zakup_window)
    {
        zakup_window->setWindowTitle(QCoreApplication::translate("zakup_window", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("zakup_window", "Subskrybuj", nullptr));
        pushButton_2->setText(QCoreApplication::translate("zakup_window", "Zakup", nullptr));
        pushButton_3->setText(QCoreApplication::translate("zakup_window", "Wypo\305\274ycz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zakup_window: public Ui_zakup_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZAKUP_WINDOW_H
