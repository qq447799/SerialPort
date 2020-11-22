#include "mainwindow.h"
#include <QApplication>
#include "headfile.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    PortObj port;

    QObject::connect(&w,SIGNAL(m_portinfo_sig(int)),&port,SLOT(p_portinfo_slot(int)),Qt::QueuedConnection);
    QObject::connect(&port,SIGNAL(p_portinfo_sig(int)),&w,SLOT(m_portinfo_slot(int)),Qt::QueuedConnection);

    w.setWindowTitle(QString("qq4477-v0.03"));
    w.show();

    return a.exec();
}
