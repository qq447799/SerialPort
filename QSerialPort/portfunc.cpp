#include "portthread.h"

extern PortInfo_Class PortInfo;

int PortObj::open_port(void)
{
    serialPort->setPortName(PortInfo.PortNum);
    if(serialPort->open(QIODevice::ReadWrite))
    {
        if(PortInfo.Baud == 0)
            serialPort->setBaudRate(QSerialPort::Baud1200);
        else if(PortInfo.Baud == 1)
            serialPort->setBaudRate(QSerialPort::Baud2400);
        else if(PortInfo.Baud == 2)
            serialPort->setBaudRate(QSerialPort::Baud4800);
        else if(PortInfo.Baud == 3)
            serialPort->setBaudRate(QSerialPort::Baud9600);
        else if(PortInfo.Baud == 4)
            serialPort->setBaudRate(QSerialPort::Baud19200);
        else if(PortInfo.Baud == 5)
            serialPort->setBaudRate(QSerialPort::Baud38400);
        else if(PortInfo.Baud == 6)
            serialPort->setBaudRate(QSerialPort::Baud57600);
        else if(PortInfo.Baud == 7)
            serialPort->setBaudRate(QSerialPort::Baud115200);
        else
            return 2;//波特率错误
        if(PortInfo.Check == 0)
            serialPort->setParity(QSerialPort::NoParity);
        else if(PortInfo.Check == 1)
            serialPort->setParity(QSerialPort::OddParity);
        else if(PortInfo.Check == 2)
            serialPort->setParity(QSerialPort::EvenParity);
        else
            return 3;//检验位错误
        if(PortInfo.Stop == 0)
            serialPort->setStopBits(QSerialPort::OneStop);
        else if(PortInfo.Stop == 1)
        {
            return 4;;//停止位错误
            serialPort->setStopBits(QSerialPort::OneStop);
        }
        else if(PortInfo.Stop == 2)
            serialPort->setStopBits(QSerialPort::TwoStop);
        else
         return 5;//停止位错误
        if(PortInfo.Data == 0)
            serialPort->setDataBits(QSerialPort::Data6);
        else if(PortInfo.Data == 1)
            serialPort->setDataBits(QSerialPort::Data7);
        else if(PortInfo.Data == 2)
            serialPort->setDataBits(QSerialPort::Data8);
        else
            return 6;//数据位错误


        connect(serialPort, &QSerialPort::readyRead,this, &PortObj::read_data);

        return 8;//打开串口成功
    }
    else
    {
        return 7;//打开串口错误
    }
    return 9;//未知错误
}
int PortObj::close_port(void)
{
    serialPort->clear();
    serialPort->close();
    return 10;//串口关闭成功
}
void PortObj::DRT_set(bool type)
{
    if(type == true)
        serialPort->setDataTerminalReady(true);
    else if(type == false)
        serialPort->setDataTerminalReady(false);
    else
        serialPort->setDataTerminalReady(false);
}
void PortObj::RTS_set(bool type)
{
    if(type == true)
        serialPort->setRequestToSend(true);
    else if(type == false)
        serialPort->setRequestToSend(false);
    else
        serialPort->setRequestToSend(false);
}
