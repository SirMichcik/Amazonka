#ifndef BIBLIOTEKA_WINDOW_H
#define BIBLIOTEKA_WINDOW_H

#include "user.h"
#include <QDialog>

namespace Ui {
class biblioteka_window;
}

class biblioteka_window : public QDialog
{
    Q_OBJECT

public:
    explicit biblioteka_window(User* user, QWidget *parent = nullptr);
    ~biblioteka_window();

private slots:
    void onMenuClicked();

private:
    Ui::biblioteka_window *ui;
    int numberOfFilms;
    int numberOfSeries;
    int numberOfBooks;

    void createButtons(User* user, const QString& type, const QString& buttonTextPrefix, QWidget* scrollAreaWidget);
    int count(QString type);
    void use(User* user, int content_id);

    User user;
};

#endif // BIBLIOTEKA_WINDOW_H
