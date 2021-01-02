#ifndef CHECKWIN_H
#define CHECKWIN_H

#include <QWidget>
#include "headfile.h"

namespace Ui {
class subwin_check;
}

class subwin_check : public QWidget
{
    Q_OBJECT

public:
    explicit subwin_check(QWidget *parent = 0);
    ~subwin_check();

private slots:
    void on_pushButton_confirm_checkwin_clicked();
    void on_pushButton_cancel_checkwin_clicked();

signals:
    void subwin_check_sig(int type);
private:
    Ui::subwin_check *ui;
};

#endif // CHECKWIN_H
