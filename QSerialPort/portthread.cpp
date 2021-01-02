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
    case OPENPORT://打开串口
        ret = open_port();
        break;
    case CLOSEPORT://关闭串口
        ret = close_port();
        break;
    case SENDDATA://发送数据
        ret = send_data();
        break;
    case DTRSET://DTR选择
        ret = DRT_set(true);
        break;
    case DTRCANCEL://DTR取消
        ret = DRT_set(false);
        break;
    case RTSSET://RTS选择
        ret = RTS_set(true);
        break;
    case RTSCANCEL://RTS取消
        ret = RTS_set(false);
        break;
    default:
        ret = UNKNOWERR;//未知错误
        break;
    }

    if(ret)
        emit p_portinfo_sig(ret);
}
void PortObj::read_data(void)
{
    if(Timing == false)
    {
        Timing = true;
        mstimer->start(10);
    }
}
void PortObj::timer_read_slot(void)
{
    QByteArray  RecvBuf;
    QString TmpStr;
    int i = 0,len = 0;

    Timing = false;
    mstimer->stop();

    RecvBuf = serialPort->readAll();
    len = RecvBuf.length();
    if(len < 1)
        return;
    if(Flags.encode == HEXCODE)
    {
        TmpStr = ExChange.ByteArrayToHexStr(RecvBuf);
        ShowBuf.str[ShowBuf.wp] = TmpStr;
    }
    else if(Flags.encode == TUF8CODE)
    {
        ShowBuf.str[ShowBuf.wp] = QString::fromLocal8Bit(RecvBuf);
    }
    else
    {
        for(i = 0;i < len;i++)
            ShowBuf.str[ShowBuf.wp][i] = RecvBuf[i];
    }

    Mutex_Show.lock();
    if(++ShowBuf.wp >= MAXBUFNUM)
        ShowBuf.wp = 0;
    if(++ShowBuf.num > MAXBUFNUM)
        ShowBuf.num = MAXBUFNUM;
    Mutex_Show.unlock();
    emit p_portinfo_sig(SHOWDATA);
}

int PortObj::send_data(void)
{
    QByteArray senddata;
    if(serialPort->isOpen())
    {
        switch (Flags.encode) {
        case ASCIICODE:
            senddata = SendBuf.toUtf8();
            if(Flags.enter == true)
                senddata += 0x0D;
            serialPort->write(senddata);
            break;
        case HEXCODE:
            if(Flags.enter == true)
                SendHexBuf += 0x0D;
            serialPort->write(SendHexBuf);
            break;
        case TUF8CODE:
            senddata = SendBuf.toUtf8();
            if(Flags.enter == true)
                senddata += 0x0D;
            serialPort->write(senddata);
            break;
        default:
            break;
        }
    }
    else
        return PORTNOTOPEN;

    return 0;
}

















