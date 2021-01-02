#ifndef FILETHREAD_H
#define FILETHREAD_H

#include "headfile.h"

#define FILEBUFNUM    30

class FileObj : public QObject
{
    Q_OBJECT
public:
    explicit FileObj();
    ~FileObj();
public slots:
    void f_fileinfo_slot(int type);
signals:
    void f_fileinfo_sig(int type);
private:
    QFile *filetxt;
    QThread *filethread;
public:
    int open_file(void);
    int close_file(void);
    int save_file_data(void);
};
class FileInfo_Class //: public Buf_Class
{
public:
    QString filename;
    QString str[FILEBUFNUM];
    int wp;
    int rp;
    int num;
};

#endif // FILETHREAD_H
