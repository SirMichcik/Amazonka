#ifndef ADD_WINDOW_H
#define ADD_WINDOW_H

#include <QDialog>
#include "content.h"

namespace Ui {
class add_window;
}

class add_window : public QDialog {
    Q_OBJECT

public:
    explicit add_window(QDialog *parent = nullptr);
    ~add_window();

private slots:
    void on_saveButton_clicked();

private:
    Ui::add_window *ui;
    Content content;
};


#endif // ADD_WINDOW_H
