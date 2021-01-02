#include "filethread.h"
#include "mainwindow.h"

FileInfo_Class FileBuf;
QMutex Mutex_File;

FileObj::FileObj()
{
    filethread = new QThread();
    this->moveToThread(filethread);
    filetxt = new QFile();
    filetxt->moveToThread(filethread);
    filethread->start();
}
FileObj::~FileObj()
{

}
void FileObj::f_fileinfo_slot(int type)
{
    int ret = 0;
    switch (type) {
    case OPENFILE:
        ret = open_file();
        break;
    case CLOSEFILE:
        ret = close_file();
        break;
    case FILEDATA:
        ret = save_file_data();
        break;
    default:
        break;
    }
    if(ret)
        emit f_fileinfo_sig(ret);
}
int FileObj::open_file(void)
{
    QString dirpath = QCoreApplication::applicationDirPath();
    dirpath += "/filedir/" + FileBuf.filename + ".txt";
    filetxt->setFileName(dirpath);
    if(!filetxt->open(QIODevice::WriteOnly | QIODevice::Truncate))// | QIODevice::Text
        return OPENFILEERR;
    return 0;
}
int FileObj::close_file(void)
{
    if(filetxt->isOpen())
        filetxt->close();
    return CLOSEFILESUC;
}
int FileObj::save_file_data(void)
{
    int num = 0,num1 = 0,ret = FILENOTOPEN;
    QTextStream astream(filetxt);

    if(filetxt->isOpen())
    {
        Mutex_File.lock();
        num = FileBuf.num;
        num1 = num;
        Mutex_File.unlock();
        if(num < 1)
            return 0;
        do{
            astream << FileBuf.str[FileBuf.rp];
            FileBuf.str[FileBuf.rp].clear();
            if(++FileBuf.rp >= MAXBUFNUM)
                FileBuf.rp = 0;
        }while(--num);
        Mutex_File.lock();
        FileBuf.num -= num1;
        if(FileBuf.num < 0)
            FileBuf.num = 0;
        Mutex_File.unlock();

        ret = 0;
    }
    return ret;
}
