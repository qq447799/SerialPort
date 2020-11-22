#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portthread.h"
#include <QMutex>
#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QFileDevice>
#include <QMessageBox>

extern Buf_Class ShowBuf;
extern QMutex Mutex_Show;
extern Flag_Class Flags;

extern PortInfo_Class PortInfo;
void MainWindow::open_port_success(void)
{
    ui->comboBox_portnum->setEnabled(false);
    ui->comboBox_baud->setEnabled(false);
    ui->comboBox_check->setEnabled(false);
    ui->comboBox_data->setEnabled(false);
    ui->comboBox_stop->setEnabled(false);
    ui->pushButton_flush->setEnabled(false);
    ui->pushButton_link_cut->setText("关闭");
}

void MainWindow::close_port_success(void)
{
    ui->comboBox_portnum->setEnabled(true);
    ui->comboBox_baud->setEnabled(true);
    ui->comboBox_check->setEnabled(true);
    ui->comboBox_data->setEnabled(true);
    ui->comboBox_stop->setEnabled(true);
    ui->pushButton_flush->setEnabled(true);
    ui->pushButton_link_cut->setText("打开");
}

void MainWindow::show_data(void)
{
    QString tmpstr1;
    Mutex_Show.lock();
    int num = ShowBuf.num;
    int num1 = num;
    Mutex_Show.unlock();
    if(num < 1)
        return;
    do{
        if(Flags.showrec == true)
        {
            if(Flags.showtime == true)
            {
                QTime qtime(QTime::currentTime());
                tmpstr1 = qtime.toString("hh:mm:ss.zzz ");
                //tmpstr1 += " ";
            }
            if((Flags.changeline == true) || (Flags.showsend == true))
            {
                tmpstr1 += "rec : " + ShowBuf.str[ShowBuf.rp];
                ui->textB_Recv->append(tmpstr1);
            }
            else
            {
                tmpstr1 += ShowBuf.str[ShowBuf.rp];
                ui->textB_Recv->insertPlainText(tmpstr1);
            }
            ui->textB_Recv->moveCursor(QTextCursor::End);
        }
        ShowBuf.str[ShowBuf.rp].clear();
        if(++ShowBuf.rp >= MAXBUFNUM)
            ShowBuf.rp = 0;
    }while(--num);
    Mutex_Show.lock();
    ShowBuf.num -= num1;
    if(ShowBuf.num < 0)
        ShowBuf.num = 0;
    Mutex_Show.unlock();
}
