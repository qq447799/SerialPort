#include "portthread.h"

PortInfo_Class PortInfo;

PortObj::PortObj()
{
    portthread = new QThread();
    serialPort = new QSerialPort();
    this->moveToThread(portthread);
    serialPort->moveToThread(portthread);
    portthread->start();
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
        break;
    case 11://关闭串口
        ret = close_port();
        break;
    default:
        ret = 9;//未知错误
        break;
    }
    emit p_portinfo_sig(ret);
}
void PortObj::read_data(void)
{
//    QByteArray  recvbuf;
//    QString tmpstr;
//    int len = 0,i = 0;

//    recvbuf = serialPort->readAll();
//    len = recvbuf.length();


//        if(flags.hex == true)
//        {
//            tmpstr = ByteArrayToHexStr(recvbuf);
//            displayinfo.str[displayinfo.wp] = tmpstr;
//        }
//        else
//        {
//            if(flags.chinese == true)
//                displayinfo.str[displayinfo.wp] = QString::fromLocal8Bit(recvbuf);
//            else
//            {
//                for(i = 0;i < len;i++)
//                    displayinfo.str[displayinfo.wp][i] = recvbuf[i];
//            }

//        }

//        if(displayinfo.str[displayinfo.wp].length() < 1)
//            return;
//    if(++displayinfo.wp >= MAXBUFNUM)
//        displayinfo.wp = 0;
//    mutex_display.lock();
//    if(++displayinfo.num > MAXBUFNUM)
//        displayinfo.num -= MAXBUFNUM;
//    mutex_display.unlock();
//    emit display_sig();

}
