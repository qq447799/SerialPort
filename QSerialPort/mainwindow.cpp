#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portthread.h"
#include <QMutex>
#include <QXmlStreamReader>
#include <QFile>
#include <QFileDialog>
#include <QFileDevice>
#include <QMessageBox>
#include <QDesktopServices>

QString SendBuf;
Cmd_Class CmdBuf;
QByteArray SendHexBuf;
Buf_Class ShowBuf;
QMutex Mutex_Show;
Flag_Class Flags;

extern PortInfo_Class PortInfo;
extern StringChange_Class ExChange;
extern FileInfo_Class FileBuf;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    FixTimer = new QTimer();

    /********************查找可用串口*************************/
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


    /**************串口助手功能*************************/
    Flags.encode = ASCIICODE;
    ui->checkBox_enter->setChecked(true);
    ui->checkBox_show->setChecked(true);
    ui->comboBox_baud->setCurrentIndex(7);
    ui->comboBox_check->setCurrentIndex(0);
    ui->comboBox_data->setCurrentIndex(2);
    ui->comboBox_stop->setCurrentIndex(0);
    /************事件过滤器注册*******************/
    ui->textEdit_Send->installEventFilter(this);
    ui->lineEdit_decimal->installEventFilter(this);
    ui->lineEdit_hex->installEventFilter(this);
    /******************计算器页面*************************/
    cntwin_std = new cnt_std(this);
    ui->stackedWidget_cnt->addWidget(cntwin_std);
    ui->stackedWidget_cnt->setCurrentIndex(0);
    ui->radioButton_biaozhun->setChecked(true);
    /******************编码页面****************************/
     ui->radioButton_smallhead->setChecked(true);

    /*******************信号与曹连接*******************************/
    connect(FixTimer, SIGNAL(timeout()), this, SLOT(fixtimer_slot()));
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
        emit m_portinfo_sig(OPENPORT);
    }
    else if(data == "关闭")
        emit m_portinfo_sig(CLOSEPORT);
    else
        QMessageBox::information(NULL, "error", "link error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}
void MainWindow::m_portinfo_slot(int Type)
{
    switch (Type) {
    case BAUDERR://波特率错误
        QMessageBox::information(NULL, "error", "baud error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case CHECKERR://校验位错误
        QMessageBox::information(NULL, "error", "check error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case STOPWARN://停止位为1.5位，无法实现，默认设置成2位
        open_port_success();
        QMessageBox::information(NULL, "warning", "stop warning,use 1 stop", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case STOPERR://停止位错误
        QMessageBox::information(NULL, "error", "stop error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case DATAERR://数据位错误
        QMessageBox::information(NULL, "error", "data error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case OPENPORTERR://打开串口错误
        QMessageBox::information(NULL, "error", "port error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case OPENPORTSUC://打开串口成功
        open_port_success();
        break;
    case UNKNOWERR://未知错误
        QMessageBox::information(NULL, "error", "unknown error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case CLOSEPORTSUC://关闭串口成功
        close_port_success();
        break;
    case SHOWDATA://显示数据
        show_data();
        break;
    case PORTNOTOPEN://串口未打开
        ui->checkBox_fixtime->setChecked(false);
        FixTimer->stop();
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
    int i = 0;
    QString datasour,datadest;
    Convert_Union data;
    if(obj == ui->lineEdit_decimal)//浮点转十六进制
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyevent = static_cast<QKeyEvent*>(event);

            if((keyevent->key() == Qt::Key_Enter) || (keyevent->key() == Qt::Key_Return))
            {
                datasour = ui->lineEdit_decimal->text();
                data.data = datasour.toFloat();
                if(ui->radioButton_bighead->isChecked())
                    datadest = ExChange.ConvertUcharString(data.hexbuf,4,1);
                else
                    datadest = ExChange.ConvertUcharString(data.hexbuf,4,0);
                ui->lineEdit_hex->clear();
                ui->lineEdit_hex->setText(datadest);
                return true;
            }
            else
                return false;
        }
    }
    else if(obj == ui->lineEdit_hex)//十六进制转浮点
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyevent = static_cast<QKeyEvent*>(event);

            if((keyevent->key() == Qt::Key_Enter) || (keyevent->key() == Qt::Key_Return))
            {
                datasour = ui->lineEdit_hex->text();
                if(ui->radioButton_bighead->isChecked())
                    datadest = ExChange.HexStrToFloatStr(datasour,1);
                else
                    datadest = ExChange.HexStrToFloatStr(datasour,0);
                if(datadest == ' ')
                {
                    QMessageBox::information(NULL, "错误", "数据超范围", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

                    return false;
                }
                ui->lineEdit_decimal->clear();
                ui->lineEdit_decimal->setText(datadest);
                return true;
            }
            else
                return false;
        }
    }
    else if(obj == ui->textEdit_Send)//控制台按回车发送数据
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyevent = static_cast<QKeyEvent*>(event);
            if(keyevent->key() == Qt::Key_Up)
            {
                CmdBuf.tmpnum -= 1;
                if(CmdBuf.tmpnum < 0)
                    CmdBuf.tmpnum = 0;
                ui->textEdit_Send->clear();
                ui->textEdit_Send->append(CmdBuf.str[CmdBuf.tmpnum]);
            }
            else if(keyevent->key() == Qt::Key_Down)
            {
                CmdBuf.tmpnum += 1;
                if(CmdBuf.tmpnum > CmdBuf.curnum)
                    CmdBuf.tmpnum = CmdBuf.curnum;
                ui->textEdit_Send->clear();
                ui->textEdit_Send->append(CmdBuf.str[CmdBuf.tmpnum]);
            }
            else if((keyevent->key() == Qt::Key_Enter) || (keyevent->key() == Qt::Key_Return))
            {
                if(Flags.encode == HEXCODE)
                {
                    QMessageBox::information(NULL, "point out", "请按“常用操作”中“发送”按钮", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

                    return false;
                }
                SendBuf = ui->textEdit_Send->toPlainText();
                CmdBuf.str[CmdBuf.curnum] = SendBuf;
                CmdBuf.curnum++;
                if(CmdBuf.curnum > (MAXCMDNUM - 1))
                {
                    CmdBuf.curnum = MAXCMDNUM - 1;
                    for(i = 0;i < (MAXCMDNUM - 1);i++)
                        CmdBuf.str[i] = CmdBuf.str[i + 1];
                }
                CmdBuf.tmpnum = CmdBuf.curnum;

                if(SendBuf == "clear")
                    ui->textB_Recv->clear();
                else
                    emit m_portinfo_sig(SENDDATA);
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
        emit m_portinfo_sig(DTRSET);
    else
        emit m_portinfo_sig(DTRCANCEL);
}

void MainWindow::on_checkBox_RTS_clicked()
{
    if(ui->checkBox_RTS->isChecked())
        emit m_portinfo_sig(RTSSET);
    else
        emit m_portinfo_sig(RTSCANCEL);
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
    {
        QMessageBox::information(NULL, "error", "no data", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
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
    emit m_portinfo_sig(SENDDATA);
}

void MainWindow::on_checkBox_savefile_clicked()
{
    QString tmpstr;

    if(ui->checkBox_savefile->isChecked())
    {
        tmpstr = ui->lineEdit_filename->text();
        if(tmpstr.length() < 1)
        {
            QDate qdata(QDate::currentDate());
            tmpstr = qdata.toString("yyyyMMdd");
            tmpstr += "-";
            QTime qtime(QTime::currentTime());
            tmpstr += qtime.toString("hhmmss");
            ui->lineEdit_filename->setText(tmpstr);
        }

        FileBuf.filename = ui->lineEdit_filename->text();
        Flags.savefile = true;
        emit m_fileinfo_sig(OPENFILE);
    }
    else
    {
        Flags.savefile = false;
        ui->lineEdit_filename->clear();
        emit m_fileinfo_sig(CLOSEFILE);
    }
}
void MainWindow::m_fileinfo_slot(int Type)
{
    switch (Type) {
    case OPENFILEERR:
        ui->lineEdit_filename->clear();
        QMessageBox::information(NULL, "error", "openfile error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        break;
    case CLOSEFILESUC:
        ui->lineEdit_filename->clear();
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_opendir_clicked()
{
    QString dirpath = QCoreApplication::applicationDirPath();

    dirpath += "/filedir";

    QDesktopServices::openUrl(QUrl::fromLocalFile(dirpath));
}

void MainWindow::on_checkBox_fixtime_clicked()
{
    QString tmpstr;

    if(ui->checkBox_fixtime->isChecked())
    {
        tmpstr = ui->lineEdit_fixtime_ms->text();
        if(tmpstr.toInt() < 1)
        {
            QMessageBox::information(NULL, "error", "fixtime error", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            ui->checkBox_fixtime->setChecked(false);
            return;
        }
        FixTimer->start(tmpstr.toInt());
    }
    else
    {
        FixTimer->stop();
    }
}

void MainWindow::on_comboBox_encode_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        Flags.encode = ASCIICODE;
        break;
    case 1:
        Flags.encode = TUF8CODE;
        break;
    case 2:
        Flags.encode = HEXCODE;
        break;
    default:
        break;
    }
}

void MainWindow::on_checkBox_enter_clicked()
{
    if(ui->checkBox_enter->isChecked())
    {
        Flags.enter = true;
    }
    else
    {
        Flags.enter = false;
    }
}


void MainWindow::on_pushButton_check_clicked()
{
     checkwin = new subwin_check();
     checkwin->setAttribute(Qt::WA_DeleteOnClose);
     checkwin->show();
     connect(checkwin,SIGNAL(subwin_check_sig(int)),this,SLOT(subwin_check_slot(int)));
}




void MainWindow::on_radioButton_biaozhun_clicked()
{
    ui->stackedWidget_cnt->setCurrentIndex(0);
}
