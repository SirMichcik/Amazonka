#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include "user.h"

#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QHBoxLayout>

namespace Ui {
class menu_window;
}

class menu_window : public QDialog
{
    Q_OBJECT

public:
    explicit menu_window(User* user, QWidget *parent = nullptr);
    ~menu_window();

private slots:
    void edit(QString title);
    void onBibliotekaClicked();

private:
    void createButtons(User* user, const QString& type, const QString& buttonTextPrefix, QWidget* scrollAreaWidget);
    void createButton(const QString& text, const QSize& size, const QPoint& position, std::function<void()> callback);
    void add();
    void generate_raport();
    void use(User* user, int content_id);
    int count(QString type);

    Ui::menu_window *ui;
    int numberOfFilms;
    int numberOfSeries;
    int numberOfBooks;

    User user;
};

#endif // MENU_WINDOW_H
