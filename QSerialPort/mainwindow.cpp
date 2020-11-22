#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portthread.h"
#include <QMutex>
#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QFileDevice>
#include <QMessageBox>

QString SendBuf;
QByteArray SendHexBuf;
Buf_Class ShowBuf;
QMutex Mutex_Show;
Flag_Class Flags;

extern PortInfo_Class PortInfo;
extern StringChange_Class ExChange;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->comboBox_portnum->addItem(info.portName());
            serial.close();
        }
    }
    ui->checkBox_show->setChecked(true);
    ui->comboBox_baud->setCurrentIndex(7);
    ui->comboBox_check->setCurrentIndex(0);
    ui->comboBox_data->setCurrentIndex(2);
    ui->comboBox_stop->setCurrentIndex(0);
    ui->textEdit_Send->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_link_cut_clicked()
{
    QString data = ui->pushButton_link_cut->text();
    if(data == "打开")
    {
        PortInfo.PortNum = ui->comboBox_portnum->currentText();
        PortInfo.Baud = ui->comboBox_baud->currentIndex();
        PortInfo.Check = ui->comboBox_check->currentIndex();
        PortInfo.Data = ui->comboBox_data->currentIndex();
        PortInfo.Stop = ui->comboBox_stop->currentIndex();
        emit m_portinfo_sig(1);
    }
    else if(data == "关闭")
        emit m_portinfo_sig(11);
    else
        QMessageBox::information(NULL, "error", "link error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
void MainWindow::m_portinfo_slot(int Type)
{
    switch (Type) {
    case 2://波特率错误
        QMessageBox::information(NULL, "error", "baud error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 3://校验位错误
        QMessageBox::information(NULL, "error", "check error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 4://停止位为1.5位，无法实现，默认设置成2位
        open_port_success();
        QMessageBox::information(NULL, "warning", "stop warning,use 1 stop", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 5://停止位错误
        QMessageBox::information(NULL, "error", "stop error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 6://数据位错误
        QMessageBox::information(NULL, "error", "data error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 7://打开串口错误
        QMessageBox::information(NULL, "error", "port error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 8://打开串口成功
        open_port_success();
        break;
    case 9://未知错误
        QMessageBox::information(NULL, "error", "unknown error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 10://关闭串口成功
        close_port_success();
        break;
    case 12://显示数据
        show_data();
        break;
    case 18://串口未打开
        QMessageBox::information(NULL, "error", "port not open", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    default:
        break;
    }

}

void MainWindow::on_pushButton_flush_clicked()
{
    ui->comboBox_portnum->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->comboBox_portnum->addItem(info.portName());
            serial.close();
        }
    }
}

bool MainWindow::eventFilter(QObject *obj,QEvent *event)
{
    if(Flags.hex == true)
        return QObject::eventFilter(obj,event);
    if(obj == ui->textEdit_Send)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyevent = static_cast<QKeyEvent*>(event);
            if((keyevent->key() == Qt::Key_Enter) || (keyevent->key() == Qt::Key_Return))
            {
                SendBuf = ui->textEdit_Send->toPlainText();
                if(SendBuf == "clear")
                    ui->textB_Recv->clear();
                else
                    emit m_portinfo_sig(13);
                ui->textEdit_Send->clear();
                return true;
            }
            else
                return false;
        }
    }
    else
        return QObject::eventFilter(obj,event);
    return false;
}

void MainWindow::on_checkBox_hex_clicked()
{
    if(ui->checkBox_hex->isChecked())
    {
        Flags.hex = true;
//        ui->pushB_send->setVisible(true);
    }
    else
        Flags.hex = false;
}

void MainWindow::on_checkBox_show_clicked()
{
    if(ui->checkBox_show->isChecked())
        Flags.showrec = true;
    else
        Flags.showrec = false;
}

void MainWindow::on_pushButton_clear_send_clicked()
{
     ui->textEdit_Send->clear();
}

void MainWindow::on_pushButton_clear_rvc_clicked()
{
    ui->textB_Recv->clear();
}

void MainWindow::on_checkBox_DTR_clicked()
{
    if(ui->checkBox_DTR->isChecked())
        emit m_portinfo_sig(14);
    else
        emit m_portinfo_sig(15);
}

void MainWindow::on_checkBox_RTS_clicked()
{
    if(ui->checkBox_RTS->isChecked())
        emit m_portinfo_sig(16);
    else
        emit m_portinfo_sig(17);
}

void MainWindow::on_checkBox_show_send_clicked()
{
    if(ui->checkBox_show_send->isChecked())
        Flags.showsend = true;
    else
        Flags.showsend = false;
}

void MainWindow::on_checkBox_change_line_clicked()
{
    if(ui->checkBox_change_line->isChecked())
        Flags.changeline = true;
    else
        Flags.changeline = false;
}

void MainWindow::on_pushButton_send_clicked()
{
    QString tmpstr;
    QString tmpstr1;
    tmpstr = ui->textEdit_Send->toPlainText();
    if(tmpstr.length() < 1)
        return;
    ExChange.StringToHexByte(tmpstr,SendHexBuf);
//    if(flags.displaytime == true)
//    {
//        QTime qtime(QTime::currentTime());
//        tmpstr1 = qtime.toString("hh:mm:ss.zzz ");

//    }
    if(Flags.showsend == true)
    {
        tmpstr1 += "send : " + tmpstr;
        ui->textB_Recv->append(tmpstr1);
    }
    emit m_portinfo_sig(13);
}
