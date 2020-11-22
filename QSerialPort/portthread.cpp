#include "portthread.h"

PortInfo_Class PortInfo;
StringChange_Class ExChange;
extern Buf_Class ShowBuf;
extern QString SendBuf;
extern QMutex Mutex_Show;
extern Flag_Class Flags;
extern QByteArray SendHexBuf;

PortObj::PortObj()
{
    portthread = new QThread();
    serialPort = new QSerialPort();
    this->moveToThread(portthread);
    Timing = false;
    mstimer = new QTimer();
    serialPort->moveToThread(portthread);
    mstimer->moveToThread(portthread);
    portthread->start();
    connect(mstimer, SIGNAL(timeout()), this, SLOT(timer_read_slot()));
}
PortObj::~PortObj()
{

}
void PortObj::p_portinfo_slot(int Type)
{
    int ret = 0;
    switch (Type) {
    case 1://打开串口
        ret = open_port();
        emit p_portinfo_sig(ret);
        break;
    case 11://关闭串口
        ret = close_port();
        emit p_portinfo_sig(ret);
        break;
    case 13://发送数据
        send_data();
        break;
    case 14://DTR选择
        DRT_set(true);
        break;
    case 15://DTR取消
        DRT_set(false);
        break;
    case 16://RTS选择
        RTS_set(true);
        break;
    case 17://RTS取消
        RTS_set(false);
        break;
    default:
        ret = 9;//未知错误
        emit p_portinfo_sig(ret);
        break;
    }

}
void PortObj::read_data(void)
{
    if(Timing == false)
    {
        Timing = true;
        mstimer->start(20);
    }
}
void PortObj::timer_read_slot(void)
{
    QByteArray  RecvBuf;
    QString TmpStr;
    int len = 0,i = 0;

    RecvBuf = serialPort->readAll();
    if(RecvBuf.length() < 1)
        return;
    if(Flags.hex == true)
    {
        TmpStr = ExChange.ByteArrayToHexStr(RecvBuf);
        ShowBuf.str[ShowBuf.wp] = TmpStr;
    }
    else
    {
        ShowBuf.str[ShowBuf.wp] = QString::fromLocal8Bit(RecvBuf);
    }

    Mutex_Show.lock();
    if(++ShowBuf.wp >= MAXBUFNUM)
        ShowBuf.wp = 0;
    if(++ShowBuf.num > MAXBUFNUM)
        ShowBuf.num = MAXBUFNUM;
    Mutex_Show.unlock();
    emit p_portinfo_sig(12);
}

void PortObj::send_data(void)
{
    if(serialPort->isOpen())
    {
        if(Flags.hex == false)
        {
            QByteArray senddata = SendBuf.toUtf8();

            senddata += 0x0D;
            serialPort->write(senddata);
        }
        else
            serialPort->write(SendHexBuf);
    }
    else
        emit p_portinfo_sig(18);
}

















