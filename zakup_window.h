#ifndef ZAKUP_WINDOW_H
#define ZAKUP_WINDOW_H

#include "content.h"
#include "zakup.h"
#include "user.h"

#include <QDialog>

namespace Ui {
class zakup_window;
}

class zakup_window : public QDialog
{
    Q_OBJECT

public:
    explicit zakup_window(Content content, User user, QDialog *parent = nullptr);
    ~zakup_window();

private slots:
    void onSubskrybujClicked();
    void onZakupClicked();
    void onWypozyczClicked();

private:
    Ui::zakup_window *ui;
    zakup zakup;
    Content content;
    User user;
};

#endif // ZAKUP_WINDOW_H
