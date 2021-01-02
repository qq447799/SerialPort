#ifndef SUBWIN_CNT_STD_H
#define SUBWIN_CNT_STD_H

#include <QWidget>
#include "headfile.h"

namespace Ui {
class cnt_std;
}

class cnt_std : public QWidget
{
    Q_OBJECT

public:
    explicit cnt_std(QWidget *parent = 0);
    ~cnt_std();
private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_jia_clicked();

    void on_pushButton_jian_clicked();

    void on_pushButton_cheng_clicked();

    void on_pushButton_chu_clicked();

    void on_pushButton_dengyu_clicked();

    void on_pushButton_dian_clicked();

    void on_pushButton_zheng_fu_clicked();

    void on_pushButton_shanchu_clicked();

    void on_pushButton_qingchu_clicked();

    void on_pushButton_kuohao_zuo_clicked();

    void on_pushButton_kuohao_you_clicked();

private:
    Ui::cnt_std *ui;
    int bracket_cnt=0;           //圆括号计数
    QString inputstr;
    bool check_error(const QString str);
    int  LastMatchingBoth(QString& str1,const char* str2);
    int  MatchingBoth(QString& str1,const char* str2);
    QQueue<QString> Split(const QString& exp);
    QQueue<QString> Transfer(QQueue<QString>& exp);
    QString ValidNum(QString str);
    QString Calculate(QString& l,QString& op,QString& r );
    QString Calculate(QQueue<QString>& exp);
    QString Result(const QString& exp);
};

#endif // CNT_STD_H
