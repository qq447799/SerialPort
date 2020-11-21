#ifndef PORTTHREAD_H
#define PORTTHREAD_H

#include "headfile.h"

class PortObj : public QObject
{
    Q_OBJECT
public:
    explicit PortObj();
    ~PortObj();
//    void delaymsec(int msec);
public slots:
    void p_portinfo_slot(int Type);

signals:
    void p_portinfo_sig(int Type);

private:
    QThread *portthread;
    QSerialPort *serialPort;
    void read_data(void);
    int open_port(void);
    int close_port(void);
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

#endif // PORTTHREAD_H
