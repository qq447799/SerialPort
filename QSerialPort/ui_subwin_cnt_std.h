/********************************************************************************
** Form generated from reading UI file 'subwin_cnt_std.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWIN_CNT_STD_H
#define UI_SUBWIN_CNT_STD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cnt_std
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_guocheng;
    QLabel *label_jieguo;
    QPushButton *pushButton_kuohao_zuo;
    QPushButton *pushButton_CE;
    QPushButton *pushButton_qingchu;
    QPushButton *pushButton_shanchu;
    QPushButton *pushButton_kuohao_you;
    QPushButton *pushButton_genhao;
    QPushButton *pushButton_pingfang;
    QPushButton *pushButton_chu;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_cheng;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_jian;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_jia;
    QPushButton *pushButton_zheng_fu;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dian;
    QPushButton *pushButton_dengyu;

    void setupUi(QWidget *cnt_std)
    {
        if (cnt_std->objectName().isEmpty())
            cnt_std->setObjectName(QStringLiteral("cnt_std"));
        cnt_std->resize(557, 538);
        horizontalLayout = new QHBoxLayout(cnt_std);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_guocheng = new QLabel(cnt_std);
        label_guocheng->setObjectName(QStringLiteral("label_guocheng"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(label_guocheng->sizePolicy().hasHeightForWidth());
        label_guocheng->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_guocheng, 0, 0, 1, 4);

        label_jieguo = new QLabel(cnt_std);
        label_jieguo->setObjectName(QStringLiteral("label_jieguo"));
        sizePolicy.setHeightForWidth(label_jieguo->sizePolicy().hasHeightForWidth());
        label_jieguo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_jieguo, 1, 0, 1, 4);

        pushButton_kuohao_zuo = new QPushButton(cnt_std);
        pushButton_kuohao_zuo->setObjectName(QStringLiteral("pushButton_kuohao_zuo"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(pushButton_kuohao_zuo->sizePolicy().hasHeightForWidth());
        pushButton_kuohao_zuo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_kuohao_zuo, 2, 0, 1, 1);

        pushButton_CE = new QPushButton(cnt_std);
        pushButton_CE->setObjectName(QStringLiteral("pushButton_CE"));
        sizePolicy1.setHeightForWidth(pushButton_CE->sizePolicy().hasHeightForWidth());
        pushButton_CE->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_CE, 2, 1, 1, 1);

        pushButton_qingchu = new QPushButton(cnt_std);
        pushButton_qingchu->setObjectName(QStringLiteral("pushButton_qingchu"));
        sizePolicy1.setHeightForWidth(pushButton_qingchu->sizePolicy().hasHeightForWidth());
        pushButton_qingchu->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_qingchu, 2, 2, 1, 1);

        pushButton_shanchu = new QPushButton(cnt_std);
        pushButton_shanchu->setObjectName(QStringLiteral("pushButton_shanchu"));
        sizePolicy1.setHeightForWidth(pushButton_shanchu->sizePolicy().hasHeightForWidth());
        pushButton_shanchu->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_shanchu, 2, 3, 1, 1);

        pushButton_kuohao_you = new QPushButton(cnt_std);
        pushButton_kuohao_you->setObjectName(QStringLiteral("pushButton_kuohao_you"));
        sizePolicy1.setHeightForWidth(pushButton_kuohao_you->sizePolicy().hasHeightForWidth());
        pushButton_kuohao_you->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_kuohao_you, 3, 0, 1, 1);

        pushButton_genhao = new QPushButton(cnt_std);
        pushButton_genhao->setObjectName(QStringLiteral("pushButton_genhao"));
        sizePolicy1.setHeightForWidth(pushButton_genhao->sizePolicy().hasHeightForWidth());
        pushButton_genhao->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_genhao, 3, 1, 1, 1);

        pushButton_pingfang = new QPushButton(cnt_std);
        pushButton_pingfang->setObjectName(QStringLiteral("pushButton_pingfang"));
        sizePolicy1.setHeightForWidth(pushButton_pingfang->sizePolicy().hasHeightForWidth());
        pushButton_pingfang->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_pingfang, 3, 2, 1, 1);

        pushButton_chu = new QPushButton(cnt_std);
        pushButton_chu->setObjectName(QStringLiteral("pushButton_chu"));
        sizePolicy1.setHeightForWidth(pushButton_chu->sizePolicy().hasHeightForWidth());
        pushButton_chu->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_chu, 3, 3, 1, 1);

        pushButton_7 = new QPushButton(cnt_std);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

        pushButton_8 = new QPushButton(cnt_std);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_9 = new QPushButton(cnt_std);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);

        pushButton_cheng = new QPushButton(cnt_std);
        pushButton_cheng->setObjectName(QStringLiteral("pushButton_cheng"));
        sizePolicy1.setHeightForWidth(pushButton_cheng->sizePolicy().hasHeightForWidth());
        pushButton_cheng->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_cheng, 4, 3, 1, 1);

        pushButton_4 = new QPushButton(cnt_std);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_4, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(cnt_std);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_5, 5, 1, 1, 1);

        pushButton_6 = new QPushButton(cnt_std);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_6, 5, 2, 1, 1);

        pushButton_jian = new QPushButton(cnt_std);
        pushButton_jian->setObjectName(QStringLiteral("pushButton_jian"));
        sizePolicy1.setHeightForWidth(pushButton_jian->sizePolicy().hasHeightForWidth());
        pushButton_jian->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_jian, 5, 3, 1, 1);

        pushButton_1 = new QPushButton(cnt_std);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_1, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(cnt_std);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);

        pushButton_3 = new QPushButton(cnt_std);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_3, 6, 2, 1, 1);

        pushButton_jia = new QPushButton(cnt_std);
        pushButton_jia->setObjectName(QStringLiteral("pushButton_jia"));
        sizePolicy1.setHeightForWidth(pushButton_jia->sizePolicy().hasHeightForWidth());
        pushButton_jia->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_jia, 6, 3, 1, 1);

        pushButton_zheng_fu = new QPushButton(cnt_std);
        pushButton_zheng_fu->setObjectName(QStringLiteral("pushButton_zheng_fu"));
        sizePolicy2.setHeightForWidth(pushButton_zheng_fu->sizePolicy().hasHeightForWidth());
        pushButton_zheng_fu->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_zheng_fu, 7, 0, 1, 1);

        pushButton_0 = new QPushButton(cnt_std);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        sizePolicy2.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_0, 7, 1, 1, 1);

        pushButton_dian = new QPushButton(cnt_std);
        pushButton_dian->setObjectName(QStringLiteral("pushButton_dian"));
        sizePolicy2.setHeightForWidth(pushButton_dian->sizePolicy().hasHeightForWidth());
        pushButton_dian->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_dian, 7, 2, 1, 1);

        pushButton_dengyu = new QPushButton(cnt_std);
        pushButton_dengyu->setObjectName(QStringLiteral("pushButton_dengyu"));
        sizePolicy1.setHeightForWidth(pushButton_dengyu->sizePolicy().hasHeightForWidth());
        pushButton_dengyu->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_dengyu, 7, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(cnt_std);

        QMetaObject::connectSlotsByName(cnt_std);
    } // setupUi

    void retranslateUi(QWidget *cnt_std)
    {
        cnt_std->setWindowTitle(QApplication::translate("cnt_std", "Form", Q_NULLPTR));
        label_guocheng->setText(QString());
        label_jieguo->setText(QString());
        pushButton_kuohao_zuo->setText(QApplication::translate("cnt_std", "(", Q_NULLPTR));
        pushButton_CE->setText(QApplication::translate("cnt_std", "CE", Q_NULLPTR));
        pushButton_qingchu->setText(QApplication::translate("cnt_std", "C", Q_NULLPTR));
        pushButton_shanchu->setText(QApplication::translate("cnt_std", "DEL", Q_NULLPTR));
        pushButton_kuohao_you->setText(QApplication::translate("cnt_std", ")", Q_NULLPTR));
        pushButton_genhao->setText(QApplication::translate("cnt_std", "\346\240\271\345\217\267", Q_NULLPTR));
        pushButton_pingfang->setText(QApplication::translate("cnt_std", "\345\271\263\346\226\271", Q_NULLPTR));
        pushButton_chu->setText(QApplication::translate("cnt_std", "\303\267", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("cnt_std", "7", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("cnt_std", "8", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("cnt_std", "9", Q_NULLPTR));
        pushButton_cheng->setText(QApplication::translate("cnt_std", "\303\227", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("cnt_std", "4", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("cnt_std", "5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("cnt_std", "6", Q_NULLPTR));
        pushButton_jian->setText(QApplication::translate("cnt_std", "\357\274\215", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("cnt_std", "1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cnt_std", "2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("cnt_std", "3", Q_NULLPTR));
        pushButton_jia->setText(QApplication::translate("cnt_std", "\357\274\213", Q_NULLPTR));
        pushButton_zheng_fu->setText(QApplication::translate("cnt_std", ".-", Q_NULLPTR));
        pushButton_0->setText(QApplication::translate("cnt_std", "0", Q_NULLPTR));
        pushButton_dian->setText(QApplication::translate("cnt_std", ".", Q_NULLPTR));
        pushButton_dengyu->setText(QApplication::translate("cnt_std", "=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cnt_std: public Ui_cnt_std {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWIN_CNT_STD_H
