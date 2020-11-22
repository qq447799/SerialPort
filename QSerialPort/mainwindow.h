#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headfile.h"

#define MAXBUFNUM 5

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool eventFilter(QObject *obj,QEvent *event);
private slots:
    void on_pushButton_link_cut_clicked();

    void on_pushButton_flush_clicked();

    void on_checkBox_hex_clicked();

    void on_checkBox_show_clicked();

    void on_pushButton_clear_send_clicked();

    void on_pushButton_clear_rvc_clicked();

    void on_checkBox_DTR_clicked();

    void on_checkBox_RTS_clicked();

    void on_checkBox_show_send_clicked();

    void on_checkBox_change_line_clicked();

    void on_pushButton_send_clicked();

public slots:
    void m_portinfo_slot(int Type);

signals:
    void m_portinfo_sig(int Type);

private:
    Ui::MainWindow *ui;
private:
    void show_data(void);
    void open_port_success(void);
    void close_port_success(void);

};
class Buf_Class
{
public:
    QString str[MAXBUFNUM];
    int wp;
    int rp;
    int num;
};
class Flag_Class
{
public:
    bool showrec = true;
    bool hex = false;
    bool changeline = false;
    bool showsend = false;
    bool showtime = false;
};
#endif // MAINWINDOW_H
