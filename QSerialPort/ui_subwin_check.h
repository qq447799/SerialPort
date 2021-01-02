/********************************************************************************
** Form generated from reading UI file 'subwin_check.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWIN_CHECK_H
#define UI_SUBWIN_CHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subwin_check
{
public:
    QWidget *widget;
    QRadioButton *radioButton_checksum;
    QRadioButton *radioButton_or;
    QRadioButton *radioButton_crc32;
    QRadioButton *radioButton_crc16;
    QRadioButton *radioButton_crc8;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_confirm_checkwin;
    QPushButton *pushButton_cancel_checkwin;

    void setupUi(QWidget *subwin_check)
    {
        if (subwin_check->objectName().isEmpty())
            subwin_check->setObjectName(QStringLiteral("subwin_check"));
        subwin_check->resize(400, 446);
        widget = new QWidget(subwin_check);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 20, 231, 281));
        radioButton_checksum = new QRadioButton(widget);
        radioButton_checksum->setObjectName(QStringLiteral("radioButton_checksum"));
        radioButton_checksum->setGeometry(QRect(40, 30, 115, 19));
        radioButton_or = new QRadioButton(widget);
        radioButton_or->setObjectName(QStringLiteral("radioButton_or"));
        radioButton_or->setGeometry(QRect(50, 80, 115, 19));
        radioButton_crc32 = new QRadioButton(widget);
        radioButton_crc32->setObjectName(QStringLiteral("radioButton_crc32"));
        radioButton_crc32->setGeometry(QRect(50, 130, 115, 19));
        radioButton_crc16 = new QRadioButton(widget);
        radioButton_crc16->setObjectName(QStringLiteral("radioButton_crc16"));
        radioButton_crc16->setGeometry(QRect(50, 170, 115, 19));
        radioButton_crc8 = new QRadioButton(widget);
        radioButton_crc8->setObjectName(QStringLiteral("radioButton_crc8"));
        radioButton_crc8->setGeometry(QRect(50, 200, 115, 19));
        radioButton_6 = new QRadioButton(widget);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(50, 240, 115, 19));
        pushButton_confirm_checkwin = new QPushButton(subwin_check);
        pushButton_confirm_checkwin->setObjectName(QStringLiteral("pushButton_confirm_checkwin"));
        pushButton_confirm_checkwin->setGeometry(QRect(60, 350, 93, 28));
        pushButton_cancel_checkwin = new QPushButton(subwin_check);
        pushButton_cancel_checkwin->setObjectName(QStringLiteral("pushButton_cancel_checkwin"));
        pushButton_cancel_checkwin->setGeometry(QRect(210, 340, 93, 28));

        retranslateUi(subwin_check);

        QMetaObject::connectSlotsByName(subwin_check);
    } // setupUi

    void retranslateUi(QWidget *subwin_check)
    {
        subwin_check->setWindowTitle(QApplication::translate("subwin_check", "Form", Q_NULLPTR));
        radioButton_checksum->setText(QApplication::translate("subwin_check", "\346\200\273\345\212\240\345\222\214", Q_NULLPTR));
        radioButton_or->setText(QApplication::translate("subwin_check", "\345\274\202\346\210\226", Q_NULLPTR));
        radioButton_crc32->setText(QApplication::translate("subwin_check", "CRC32", Q_NULLPTR));
        radioButton_crc16->setText(QApplication::translate("subwin_check", "CRC16", Q_NULLPTR));
        radioButton_crc8->setText(QApplication::translate("subwin_check", "CRC8", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("subwin_check", "RadioButton", Q_NULLPTR));
        pushButton_confirm_checkwin->setText(QApplication::translate("subwin_check", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel_checkwin->setText(QApplication::translate("subwin_check", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class subwin_check: public Ui_subwin_check {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWIN_CHECK_H
