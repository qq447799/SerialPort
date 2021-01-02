#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "headfile.h"

/*缓存大小定义*/
#define MAXBUFNUM    30
#define MAXCMDNUM    20

class subwin_check;
class cnt_std;
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
    void fixtimer_slot(void);

    void on_pushButton_link_cut_clicked();

    void on_pushButton_flush_clicked();

    void on_checkBox_show_clicked();

    void on_pushButton_clear_send_clicked();

    void on_pushButton_clear_rvc_clicked();

    void on_checkBox_DTR_clicked();

    void on_checkBox_RTS_clicked();

    void on_checkBox_show_send_clicked();

    void on_checkBox_change_line_clicked();

    void on_pushButton_send_clicked();

    void on_checkBox_savefile_clicked();

    void on_pushButton_opendir_clicked();

    void on_checkBox_fixtime_clicked();

    void on_comboBox_encode_currentIndexChanged(int index);

    void on_checkBox_enter_clicked();

    void on_pushButton_check_clicked();

    void on_radioButton_biaozhun_clicked();

public slots:
    void m_portinfo_slot(int Type);
    void m_fileinfo_slot(int Type);
    void subwin_check_slot(int Type);
signals:
    void m_portinfo_sig(int Type);
    void m_fileinfo_sig(int Type);
private:
    QTimer *FixTimer;
    Ui::MainWindow *ui;
    subwin_check *checkwin;
    cnt_std *cntwin_std;
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
    int encode;
    bool showrec = true;
    bool enter = true;
    bool changeline = false;
    bool showsend = false;
    bool showtime = false;
    bool savefile = false;
};
class Cmd_Class
{
public:
    int num;
    int tmpnum;
    int curnum;
    QString str[MAXCMDNUM];
};
union Convert_Union
{
    float data;
    unsigned char hexbuf[4];
};
#endif // MAINWINDOW_H
