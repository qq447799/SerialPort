#ifndef PORTTHREAD_H
#define PORTTHREAD_H

#include "headfile.h"

class PortObj : public QObject
{
    Q_OBJECT
public:
    explicit PortObj();
    ~PortObj();
private slots:
    void timer_read_slot(void);
public slots:
    void p_portinfo_slot(int Type);

signals:
    void p_portinfo_sig(int Type);

private:
    bool Timing;
    QTimer *mstimer;
    QThread *portthread;
    QSerialPort *serialPort;
private:
    void read_data(void);
    void send_data(void);
    int open_port(void);
    int close_port(void);
    void DRT_set(bool type);
    void RTS_set(bool type);
};

class PortInfo_Class
{
public:
    QString PortNum;
    int Baud;
    int Check;
    int Data;
    int Stop;
};
class StringChange_Class
{
public:
    QString ByteArrayToHexStr(QByteArray data)//字节转十六进制
    {
        QString temp="";
        QString hex=data.toHex();
        for (int i=0;i<hex.length();i=i+2)
        {
            temp+=hex.mid(i,2)+" ";
        }
        return temp.trimmed().toUpper();
    }
    void StringToHexByte(QString str, QByteArray &senddata)
    {
        int hexdata,lowhexdata;
            int hexdatalen = 0;
            int len = str.length();
    //        if(len%2 == 1)
    //            str.insert((len-1),'0');
    //        senddata.resize(len/2);
            char lstr,hstr;
            for(int i=0; i<len; )
            {
                //char lstr,
                hstr=str[i].toLatin1();
                if(hstr == ' ')
                {
                    i++;
                    continue;
                }
                i++;
                if(i >= len)
                    break;
                lstr = str[i].toLatin1();
                hexdata = ConvertHexChart(hstr);
                lowhexdata = ConvertHexChart(lstr);
                if((hexdata == 16) || (lowhexdata == 16))
                    break;
                else
                    hexdata = hexdata*16+lowhexdata;
                i++;
                senddata[hexdatalen] = (char)hexdata;
                hexdatalen++;
            }
            senddata.resize(hexdatalen);
    }
    char ConvertHexChart(char ch)
    {
        if((ch >= '0') && (ch <= '9'))
                    return ch-0x30;  // 0x30 对应 ‘0’
                else if((ch >= 'A') && (ch <= 'F'))
                    return ch-'A'+10;
                else if((ch >= 'a') && (ch <= 'f'))
                    return ch-'a'+10;
        //        else return (-1);
        else return ch-ch;//不在0-f范围内的会发送成0
    }
};
#endif // PORTTHREAD_H
