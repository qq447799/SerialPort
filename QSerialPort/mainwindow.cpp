#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portthread.h"
#include <QMutex>
#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QFileDevice>
#include <QMessageBox>

extern PortInfo_Class PortInfo;

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
    ui->comboBox_baud->setCurrentIndex(7);
    ui->comboBox_check->setCurrentIndex(0);
    ui->comboBox_data->setCurrentIndex(2);
    ui->comboBox_stop->setCurrentIndex(0);
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
    case 2:
        QMessageBox::information(NULL, "error", "baud error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 3:
        QMessageBox::information(NULL, "error", "check error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 4:
        ui->comboBox_portnum->setEnabled(false);
        ui->comboBox_baud->setEnabled(false);
        ui->comboBox_check->setEnabled(false);
        ui->comboBox_data->setEnabled(false);
        ui->comboBox_stop->setEnabled(false);
        ui->pushButton_flush->setEnabled(false);
        ui->pushButton_link_cut->setText("关闭");
        QMessageBox::information(NULL, "warning", "stop warning,use 1 stop", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 5:
        QMessageBox::information(NULL, "error", "stop error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 6:
        QMessageBox::information(NULL, "error", "data error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 7:
        QMessageBox::information(NULL, "error", "port error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 8://打开串口成功
        ui->comboBox_portnum->setEnabled(false);
        ui->comboBox_baud->setEnabled(false);
        ui->comboBox_check->setEnabled(false);
        ui->comboBox_data->setEnabled(false);
        ui->comboBox_stop->setEnabled(false);
        ui->pushButton_flush->setEnabled(false);
        ui->pushButton_link_cut->setText("关闭");
        break;
    case 9:
        QMessageBox::information(NULL, "error", "unknown error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case 10://关闭串口成功
        ui->comboBox_portnum->setEnabled(true);
        ui->comboBox_baud->setEnabled(true);
        ui->comboBox_check->setEnabled(true);
        ui->comboBox_data->setEnabled(true);
        ui->comboBox_stop->setEnabled(true);
        ui->pushButton_flush->setEnabled(true);
        ui->pushButton_link_cut->setText("打开");
        break;
    case 11:
        QMessageBox::information(NULL, "error", "baud error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
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
