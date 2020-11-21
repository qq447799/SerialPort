#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_link_cut_clicked();

    void on_pushButton_flush_clicked();

public slots:
    void m_portinfo_slot(int Type);

signals:
    void m_portinfo_sig(int Type);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
