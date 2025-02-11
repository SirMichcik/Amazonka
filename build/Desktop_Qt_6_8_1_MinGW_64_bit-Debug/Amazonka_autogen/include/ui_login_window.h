/********************************************************************************
** Form generated from reading UI file 'login_window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WINDOW_H
#define UI_LOGIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_window
{
public:
    QLabel *label_title;
    QLabel *label_logo;
    QLabel *label_username;
    QLineEdit *lineEdit_login;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton;

    void setupUi(QDialog *login_window)
    {
        if (login_window->objectName().isEmpty())
            login_window->setObjectName("login_window");
        login_window->resize(500, 300);
        label_title = new QLabel(login_window);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(50, 20, 400, 40));
        label_title->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_title->setFont(font);
        label_logo = new QLabel(login_window);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(300, 70, 150, 150));
        label_logo->setScaledContents(true);
        label_username = new QLabel(login_window);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(20, 90, 100, 25));
        lineEdit_login = new QLineEdit(login_window);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setGeometry(QRect(120, 90, 150, 25));
        label_password = new QLabel(login_window);
        label_password->setObjectName("label_password");
        label_password->setGeometry(QRect(20, 130, 100, 25));
        lineEdit_password = new QLineEdit(login_window);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(120, 130, 150, 25));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(login_window);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 180, 150, 35));

        retranslateUi(login_window);

        QMetaObject::connectSlotsByName(login_window);
    } // setupUi

    void retranslateUi(QDialog *login_window)
    {
        login_window->setWindowTitle(QCoreApplication::translate("login_window", "Logowanie", nullptr));
        label_title->setText(QCoreApplication::translate("login_window", "Amazonka", nullptr));
        label_logo->setPixmap(QCoreApplication::translate("login_window", ":/resources/logo.png", nullptr));
        label_username->setText(QCoreApplication::translate("login_window", "Login:", nullptr));
        label_password->setText(QCoreApplication::translate("login_window", "Has\305\202o:", nullptr));
        pushButton->setText(QCoreApplication::translate("login_window", "Zaloguj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_window: public Ui_login_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WINDOW_H
