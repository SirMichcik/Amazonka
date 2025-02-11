#ifndef login_window_H
#define login_window_H

#include <QDialog>

namespace Ui {
class login_window;
}

class login_window : public QDialog
{
    Q_OBJECT

public:
    explicit login_window(QWidget *parent = nullptr);
    ~login_window();

private slots:
    void onLoginClicked();

private:
    Ui::login_window *ui;
};

#endif // login_window_H
