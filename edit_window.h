#ifndef EDIT_WINDOW_H
#define EDIT_WINDOW_H

#include <QDialog>
#include "content.h"

namespace Ui {
class edit_window;
}

class edit_window : public QDialog {
    Q_OBJECT

public:
    explicit edit_window(const Content &content, QDialog *parent = nullptr);
    ~edit_window();

private slots:
    void on_saveButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::edit_window *ui;
    Content content;
    void loadContentData();
    void loadPicture();
};

#endif // EDIT_WINDOW_H
