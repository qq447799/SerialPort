#include "subwin_check.h"
#include "ui_subwin_check.h"

subwin_check::subwin_check(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwin_check)
{
    ui->setupUi(this);
}

subwin_check::~subwin_check()
{
    delete ui;
}

void subwin_check::on_pushButton_confirm_checkwin_clicked()
{
    int ret = CANCEL;

    if(ui->radioButton_checksum->isChecked())
        ret = CHECKSUM;
    else if(ui->radioButton_or->isChecked())
        ret = CHECKOR;
    else if(ui->radioButton_crc32->isChecked())
        ret = CHECKCRC32;
    else if(ui->radioButton_crc16->isChecked())
        ret = CHECKCRC16;
    else if(ui->radioButton_crc8->isChecked())
        ret = CHECKCRC8;
    else
        ret = CANCEL;

    emit subwin_check_sig(ret);
}

void subwin_check::on_pushButton_cancel_checkwin_clicked()
{
    emit subwin_check_sig(CANCEL);
}
