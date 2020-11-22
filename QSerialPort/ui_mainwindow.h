/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_portnum;
    QLabel *label_2;
    QComboBox *comboBox_baud;
    QLabel *label_3;
    QComboBox *comboBox_check;
    QLabel *label_5;
    QComboBox *comboBox_data;
    QLabel *label_4;
    QComboBox *comboBox_stop;
    QPushButton *pushButton_link_cut;
    QPushButton *pushButton_flush;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_DTR;
    QCheckBox *checkBox_show_send;
    QCheckBox *checkBox_RTS;
    QCheckBox *checkBox_change_line;
    QPushButton *pushButton_clear_send;
    QPushButton *pushButton_clear_rvc;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textB_Recv;
    QWidget *tab_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_show;
    QCheckBox *checkBox_hex;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_send;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_Send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(splitter_2);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_portnum = new QComboBox(groupBox);
        comboBox_portnum->setObjectName(QStringLiteral("comboBox_portnum"));

        gridLayout->addWidget(comboBox_portnum, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBox_baud = new QComboBox(groupBox);
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));

        gridLayout->addWidget(comboBox_baud, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox_check = new QComboBox(groupBox);
        comboBox_check->setObjectName(QStringLiteral("comboBox_check"));

        gridLayout->addWidget(comboBox_check, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        comboBox_data = new QComboBox(groupBox);
        comboBox_data->setObjectName(QStringLiteral("comboBox_data"));

        gridLayout->addWidget(comboBox_data, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        comboBox_stop = new QComboBox(groupBox);
        comboBox_stop->setObjectName(QStringLiteral("comboBox_stop"));

        gridLayout->addWidget(comboBox_stop, 4, 1, 1, 1);

        pushButton_link_cut = new QPushButton(groupBox);
        pushButton_link_cut->setObjectName(QStringLiteral("pushButton_link_cut"));

        gridLayout->addWidget(pushButton_link_cut, 5, 0, 1, 1);

        pushButton_flush = new QPushButton(groupBox);
        pushButton_flush->setObjectName(QStringLiteral("pushButton_flush"));

        gridLayout->addWidget(pushButton_flush, 5, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        checkBox_DTR = new QCheckBox(groupBox_2);
        checkBox_DTR->setObjectName(QStringLiteral("checkBox_DTR"));

        gridLayout_2->addWidget(checkBox_DTR, 0, 0, 1, 1);

        checkBox_show_send = new QCheckBox(groupBox_2);
        checkBox_show_send->setObjectName(QStringLiteral("checkBox_show_send"));

        gridLayout_2->addWidget(checkBox_show_send, 1, 0, 1, 1);

        checkBox_RTS = new QCheckBox(groupBox_2);
        checkBox_RTS->setObjectName(QStringLiteral("checkBox_RTS"));

        gridLayout_2->addWidget(checkBox_RTS, 0, 1, 1, 1);

        checkBox_change_line = new QCheckBox(groupBox_2);
        checkBox_change_line->setObjectName(QStringLiteral("checkBox_change_line"));

        gridLayout_2->addWidget(checkBox_change_line, 1, 1, 1, 1);

        pushButton_clear_send = new QPushButton(groupBox_2);
        pushButton_clear_send->setObjectName(QStringLiteral("pushButton_clear_send"));

        gridLayout_2->addWidget(pushButton_clear_send, 2, 0, 1, 1);

        pushButton_clear_rvc = new QPushButton(groupBox_2);
        pushButton_clear_rvc->setObjectName(QStringLiteral("pushButton_clear_rvc"));

        gridLayout_2->addWidget(pushButton_clear_rvc, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        splitter_2->addWidget(widget_2);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(6);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setTabPosition(QTabWidget::South);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textB_Recv = new QTextBrowser(tab);
        textB_Recv->setObjectName(QStringLiteral("textB_Recv"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(8);
        sizePolicy3.setHeightForWidth(textB_Recv->sizePolicy().hasHeightForWidth());
        textB_Recv->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(textB_Recv);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_show = new QCheckBox(widget);
        checkBox_show->setObjectName(QStringLiteral("checkBox_show"));

        horizontalLayout_2->addWidget(checkBox_show);

        checkBox_hex = new QCheckBox(widget);
        checkBox_hex->setObjectName(QStringLiteral("checkBox_hex"));

        horizontalLayout_2->addWidget(checkBox_hex);

        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_2->addWidget(checkBox_3);

        pushButton_send = new QPushButton(widget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout_2->addWidget(pushButton_send);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        splitter->addWidget(widget);
        textEdit_Send = new QTextEdit(splitter);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(textEdit_Send->sizePolicy().hasHeightForWidth());
        textEdit_Send->setSizePolicy(sizePolicy4);
        splitter->addWidget(textEdit_Send);
        splitter_2->addWidget(splitter);

        horizontalLayout_3->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\202\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", " \344\270\262\345\217\243\345\217\267:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", " \346\263\242\347\211\271\347\216\207:", Q_NULLPTR));
        comboBox_baud->clear();
        comboBox_baud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4800", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "38400", Q_NULLPTR)
         << QApplication::translate("MainWindow", "57600", Q_NULLPTR)
         << QApplication::translate("MainWindow", "115200", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", " \346\240\241\351\252\214\344\275\215:", Q_NULLPTR));
        comboBox_check->clear();
        comboBox_check->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\227\240\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", " \346\225\260\346\215\256\344\275\215:", Q_NULLPTR));
        comboBox_data->clear();
        comboBox_data->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "6\344\275\215", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7\344\275\215", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8\344\275\215", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", " \345\201\234\346\255\242\344\275\215:", Q_NULLPTR));
        comboBox_stop->clear();
        comboBox_stop->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1\344\275\215", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1.5\344\275\215", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2\344\275\215", Q_NULLPTR)
        );
        pushButton_link_cut->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
        pushButton_flush->setText(QApplication::translate("MainWindow", " \345\210\267\346\226\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        checkBox_DTR->setText(QApplication::translate("MainWindow", "DTR", Q_NULLPTR));
        checkBox_show_send->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\217\221\351\200\201", Q_NULLPTR));
        checkBox_RTS->setText(QApplication::translate("MainWindow", "RTS", Q_NULLPTR));
        checkBox_change_line->setText(QApplication::translate("MainWindow", "\345\270\247\346\215\242\350\241\214", Q_NULLPTR));
        pushButton_clear_send->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_clear_rvc->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        checkBox_show->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\216\245\346\224\266", Q_NULLPTR));
        checkBox_hex->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "\344\270\255\346\226\207", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("MainWindow", " \345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
