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
extern QString SendBuf;
extern QByteArray SendHexBuf;
extern PortInfo_Class PortInfo;
extern StringChange_Class ExChange;
extern FileInfo_Class FileBuf;
extern QMutex Mutex_File;

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
        if(Flags.savefile)
        {
            FileBuf.str[FileBuf.wp] = ShowBuf.str[ShowBuf.wp];

            Mutex_File.lock();
            if(++FileBuf.wp >= MAXBUFNUM)
                FileBuf.wp = 0;
            if(++FileBuf.num > MAXBUFNUM)
                FileBuf.num = MAXBUFNUM;
            Mutex_File.unlock();

            emit m_fileinfo_sig(FILEDATA);
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
void MainWindow::fixtimer_slot(void)
{
    QString tmpstr1;
    QString tmpstr = ui->textEdit_Send->toPlainText();


    if(tmpstr.length() < 1)
    {
        QMessageBox::information(NULL, "error", "no data", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        FixTimer->stop();
        ui->checkBox_fixtime->setChecked(false);
        return;
    }
    switch (Flags.encode) {
    case ASCIICODE:
        if(Flags.showsend == true)
        {
            tmpstr1 += "send : " + tmpstr;
            ui->textB_Recv->append(tmpstr1);
        }
        SendBuf = tmpstr;
        break;
    case TUF8CODE:

        break;
    case HEXCODE:
        ExChange.StringToHexByte(tmpstr,SendHexBuf);
        if(Flags.showsend == true)
        {
            tmpstr1 += "send : " + tmpstr;
            ui->textB_Recv->append(tmpstr1);
        }
        break;
    default:
        break;
    }

    emit m_portinfo_sig(SENDDATA);
}
void MainWindow::subwin_check_slot(int Type)
{
    QString tmpstr;
    QString tmpstr1;
    QByteArray HexBuf,data;
    int i = 0;
    unsigned char sum8 = 0;
    unsigned int sum = 0;

    switch (Type) {
    case CHECKCRC32:

        break;
    case CHECKCRC16:

        break;
    case CHECKCRC8:

        break;
    case CHECKSUM:
        tmpstr = ui->textEdit_Send->toPlainText();
        if(tmpstr.length() < 1)
        {
            QMessageBox::information(NULL, "error", "no data", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }
        ExChange.StringToHexByte(tmpstr,HexBuf);
        for(i = 0;i < HexBuf.length();i++)
            sum8 += HexBuf.at(i);

        data[0] = sum8;
        tmpstr1 = ExChange.ByteArrayToHexStr(data);
        ui->lineEdit_check->setText(tmpstr1);
        break;
    case CHECKOR:

        break;
    case CANCEL:

        break;
    default:
        break;
    }
    checkwin->close();
}
