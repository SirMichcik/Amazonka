#ifndef RAPORT_WINDOW_H
#define RAPORT_WINDOW_H

#include <QWidget>

namespace Ui {
class raport_window;
}

class raport_window : public QWidget
{
    Q_OBJECT

public:
    explicit raport_window(QWidget *parent = nullptr);
    ~raport_window();

    void updateTable();

private:
    Ui::raport_window *ui;
};

#endif // RAPORT_WINDOW_H
