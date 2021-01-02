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
    int send_data(void);
    int open_port(void);
    int close_port(void);
    int DRT_set(bool type);
    int RTS_set(bool type);
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
    QString ConvertUcharString(unsigned char *ch,int len,int flagss)
    {
        int i = 0;
        unsigned char data = 0x00;
        QString ret;
        if(flagss == 0)
        {
        for(i = 0;i < len;i++)
        {
            data = ch[i] >> 4;//高4位转换
            if(data <= 0x09)
                ret[i*3] = data + 0x30;
            else if((data >= 0x0A) && (data <= 0x0F))
                ret[i*3] = data - 10 + 0x41;
            else
                ret[i*3] = 0x30;

            data = ch[i] & 0x0F;//低4位转换
            if(data <= 0x09)
                ret[i*3+1] = data + 0x30;
            else if((data >= 0x0A) && (data <= 0x0F))
                ret[i*3+1] = data - 10 + 0x41;
            else
                ret[i*3+1] = 0x30;
            ret[i*3+2] = 0x20;
        }
        }
        else
        {
            for(i = 0;i < len;i++)
            {
                data = ch[i] >> 4;//高4位转换
                if(data <= 0x09)
                    ret[(len - 1 - i)*3] = data + 0x30;
                else if((data >= 0x0A) && (data <= 0x0F))
                    ret[(len - 1 - i)*3] = data - 10 + 0x41;
                else
                    ret[(len - 1 - i)*3] = 0x30;

                data = ch[i] & 0x0F;//低4位转换
                if(data <= 0x09)
                    ret[(len - 1 - i)*3+1] = data + 0x30;
                else if((data >= 0x0A) && (data <= 0x0F))
                    ret[(len - 1 - i)*3+1] = data - 10 + 0x41;
                else
                    ret[(len - 1 - i)*3+1] = 0x30;
                ret[(len - 1 - i)*3+2] = 0x20;
            }
        }
        return ret;
    }
    QString HexStrToFloatStr(QString str,int flagss)
    {
        int i = 0,j = 0;
         char tmp = 0;
        float dataf = 0.0;
        unsigned char data[4] = {0x00};
        QString ret = " ",tmpstr;
        j = str.length();
        for(i = 0;i < j;i++)
        {
            if(str.at(i) != ' ')
              tmpstr += str.at(i);

        }
        if(flagss == 0)
        {
        for(i = 0;i < 4;i++)
        {
            tmp = tmpstr[i * 2].toLatin1();//高4位转换
            if((tmp >= '0') && (tmp <= '9'))
                 data[i] = (tmp-0x30) << 4;  // 0x30 对应 ‘0’
            else if((tmp >= 'A') && (tmp <= 'F'))
                  data[i] = (tmp-'A'+10) << 4;
            else if((tmp >= 'a') && (tmp <= 'f'))
                  data[i] = (tmp-'a'+10) << 4;
            else
                return ret;
            tmp = tmpstr[i * 2 + 1].toLatin1();//低4位转换
            if((tmp >= '0') && (tmp <= '9'))
                 data[i] |= tmp-0x30;  // 0x30 对应 ‘0’
            else if((tmp >= 'A') && (tmp <= 'F'))
                  data[i] |= tmp-'A'+10;
            else if((tmp >= 'a') && (tmp <= 'f'))
                  data[i] |= tmp-'a'+10;
            else
                return ret;

        }
        }
        else
        {
            for(i = 0;i < 4;i++)
            {
                tmp = tmpstr[(3 - i) * 2].toLatin1();//高4位转换
                if((tmp >= '0') && (tmp <= '9'))
                     data[i] = (tmp-0x30) << 4;  // 0x30 对应 ‘0’
                else if((tmp >= 'A') && (tmp <= 'F'))
                      data[i] = (tmp-'A'+10) << 4;
                else if((tmp >= 'a') && (tmp <= 'f'))
                      data[i] = (tmp-'a'+10) << 4;
                else
                    return ret;
                tmp = tmpstr[(3 - i) * 2 + 1].toLatin1();//低4位转换
                if((tmp >= '0') && (tmp <= '9'))
                     data[i] |= tmp-0x30;  // 0x30 对应 ‘0’
                else if((tmp >= 'A') && (tmp <= 'F'))
                      data[i] |= tmp-'A'+10;
                else if((tmp >= 'a') && (tmp <= 'f'))
                      data[i] |= tmp-'a'+10;
                else
                    return ret;
            }

        }
        memcpy(&dataf,data,4);
        //dataf = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
        ret = QString("%1").arg(dataf);
        return ret;
    }
};
#endif // PORTTHREAD_H
