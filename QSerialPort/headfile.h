#ifndef HEADFILE_H
#define HEADFILE_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QLabel>
#include <QTimer>
#include <QApplication>
#include <QTime>
#include <windows.h>
#include <QString>
#include <dbt.h>
#include <QDebug>
#include <devguid.h>
#include <QMutex>
#include <SetupAPI.h>
#include <InitGuid.h>
#include <QColumnView>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QWidget>
#include <QThread>
#include "portthread.h"
#include "mainwindow.h"

#include "QKeyEvent"

#define OpenPort          1
#define OpenPortSucc      2
#define ClosePort         3
//enum DataInfo_Enum
//{
//    OpenPort,
//    OpenPortSucc,
//    ClosePort,
//};

#endif // HEADFILE_H
