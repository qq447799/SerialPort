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
#include <QStack>
#include <QQueue>
#include "portthread.h"
#include "mainwindow.h"
#include "QTextCodec"
#include "QKeyEvent"
#include "filethread.h"
#include "subwin_check.h"
#include "subwin_cnt_std.h"

/*串口信号定义*/
#define OPENPORT            1   //打开串口
#define BAUDERR             2   //波特路错误
#define CHECKERR            3   //校验位错误
#define STOPWARN            4   //停止位警告，无法设置1.5停止位，自动设置为2位
#define STOPERR             5   //停止位错误
#define DATAERR             6   //数据位错误
#define OPENPORTERR         7   //打开串口错误
#define OPENPORTSUC         8   //打开串口成功
#define UNKNOWERR           9   //位置错误
#define CLOSEPORTSUC        10  //关闭串口成功
#define CLOSEPORT           11  //关闭串口
#define SHOWDATA            12  //显示数据
#define SENDDATA            13  //发送数据
#define DTRSET              14  //DTR设置
#define DTRCANCEL           15  //DTR取消
#define RTSSET              16  //RTS设置
#define RTSCANCEL           17  //RTS取消
#define PORTNOTOPEN         18  //串口未打开

/*文件信号定义*/
#define OPENFILE            30  //打开文件
#define OPENFILEERR         31  //打开文件错误
#define CLOSEFILE           32  //关闭文件
#define FILEDATA            33  //文件数据
#define CLOSEFILESUC        34  //关闭文件成功
#define FILENOTOPEN         35  //文件没有打开
/*定时发送数据信号定义*/
//#define

/*编码格式定义*/
#define ASCIICODE           60  //ASCII码
#define TUF8CODE            61  //UTF-8编码，能显示该格式中文
#define HEXCODE             62  //十六进制

/*校验子窗口定义*/
#define CHECKCRC32          70  //CRC32校验
#define CHECKCRC16          71  //CRC16校验
#define CHECKCRC8           72  //CRC8校验
#define CHECKOR             73  //异或校验
#define CHECKSUM            74  //总加和校验
#define CONFIRM             75  //确认
#define CANCEL              76  //取消

#endif // HEADFILE_H
