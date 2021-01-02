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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
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
    QPushButton *pushButton_clear_send;
    QCheckBox *checkBox_DTR;
    QCheckBox *checkBox_RTS;
    QCheckBox *checkBox_change_line;
    QCheckBox *checkBox_show_send;
    QPushButton *pushButton_send;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_filename;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_savefile;
    QPushButton *pushButton_opendir;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_enter;
    QCheckBox *checkBox_fixtime;
    QLabel *label_7;
    QLineEdit *lineEdit_fixtime_ms;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textB_Recv;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_biaozhun;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_8;
    QStackedWidget *stackedWidget_cnt;
    QWidget *tab_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_decimal;
    QLineEdit *lineEdit_hex;
    QWidget *widget_3;
    QRadioButton *radioButton_bighead;
    QRadioButton *radioButton_smallhead;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_show;
    QComboBox *comboBox_encode;
    QPushButton *pushButton_check;
    QLineEdit *lineEdit_check;
    QPushButton *pushButton_clear_rvc;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_Send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1107, 759);
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
        pushButton_clear_send = new QPushButton(groupBox_2);
        pushButton_clear_send->setObjectName(QStringLiteral("pushButton_clear_send"));

        gridLayout_2->addWidget(pushButton_clear_send, 2, 0, 1, 1);

        checkBox_DTR = new QCheckBox(groupBox_2);
        checkBox_DTR->setObjectName(QStringLiteral("checkBox_DTR"));

        gridLayout_2->addWidget(checkBox_DTR, 0, 0, 1, 1);

        checkBox_RTS = new QCheckBox(groupBox_2);
        checkBox_RTS->setObjectName(QStringLiteral("checkBox_RTS"));

        gridLayout_2->addWidget(checkBox_RTS, 0, 1, 1, 1);

        checkBox_change_line = new QCheckBox(groupBox_2);
        checkBox_change_line->setObjectName(QStringLiteral("checkBox_change_line"));

        gridLayout_2->addWidget(checkBox_change_line, 1, 1, 1, 1);

        checkBox_show_send = new QCheckBox(groupBox_2);
        checkBox_show_send->setObjectName(QStringLiteral("checkBox_show_send"));

        gridLayout_2->addWidget(checkBox_show_send, 1, 0, 1, 1);

        pushButton_send = new QPushButton(groupBox_2);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        gridLayout_2->addWidget(pushButton_send, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(widget_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        lineEdit_filename = new QLineEdit(groupBox_4);
        lineEdit_filename->setObjectName(QStringLiteral("lineEdit_filename"));

        verticalLayout_2->addWidget(lineEdit_filename);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_savefile = new QCheckBox(groupBox_4);
        checkBox_savefile->setObjectName(QStringLiteral("checkBox_savefile"));

        horizontalLayout_4->addWidget(checkBox_savefile);

        pushButton_opendir = new QPushButton(groupBox_4);
        pushButton_opendir->setObjectName(QStringLiteral("pushButton_opendir"));

        horizontalLayout_4->addWidget(pushButton_opendir);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        checkBox_enter = new QCheckBox(groupBox_3);
        checkBox_enter->setObjectName(QStringLiteral("checkBox_enter"));

        gridLayout_3->addWidget(checkBox_enter, 0, 0, 1, 1);

        checkBox_fixtime = new QCheckBox(groupBox_3);
        checkBox_fixtime->setObjectName(QStringLiteral("checkBox_fixtime"));

        gridLayout_3->addWidget(checkBox_fixtime, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_fixtime_ms = new QLineEdit(groupBox_3);
        lineEdit_fixtime_ms->setObjectName(QStringLiteral("lineEdit_fixtime_ms"));
        lineEdit_fixtime_ms->setMaximumSize(QSize(80, 16777215));

        gridLayout_3->addWidget(lineEdit_fixtime_ms, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        splitter_2->addWidget(widget_2);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(9);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setFrameShadow(QFrame::Raised);
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(0);
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
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        radioButton_biaozhun = new QRadioButton(tab_2);
        radioButton_biaozhun->setObjectName(QStringLiteral("radioButton_biaozhun"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(radioButton_biaozhun->sizePolicy().hasHeightForWidth());
        radioButton_biaozhun->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(radioButton_biaozhun, 0, 0, 1, 1);

        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        sizePolicy4.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(radioButton, 1, 0, 1, 1);

        radioButton_3 = new QRadioButton(tab_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_3, 3, 0, 1, 1);

        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        sizePolicy5.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_2, 2, 0, 1, 1);

        radioButton_5 = new QRadioButton(tab_2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        sizePolicy5.setHeightForWidth(radioButton_5->sizePolicy().hasHeightForWidth());
        radioButton_5->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_5, 5, 0, 1, 1);

        radioButton_6 = new QRadioButton(tab_2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        sizePolicy5.setHeightForWidth(radioButton_6->sizePolicy().hasHeightForWidth());
        radioButton_6->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_6, 6, 0, 1, 1);

        radioButton_7 = new QRadioButton(tab_2);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        sizePolicy5.setHeightForWidth(radioButton_7->sizePolicy().hasHeightForWidth());
        radioButton_7->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_7, 7, 0, 1, 1);

        radioButton_4 = new QRadioButton(tab_2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        sizePolicy5.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_4, 4, 0, 1, 1);

        radioButton_9 = new QRadioButton(tab_2);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        sizePolicy5.setHeightForWidth(radioButton_9->sizePolicy().hasHeightForWidth());
        radioButton_9->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_9, 9, 0, 1, 1);

        radioButton_8 = new QRadioButton(tab_2);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        sizePolicy5.setHeightForWidth(radioButton_8->sizePolicy().hasHeightForWidth());
        radioButton_8->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(radioButton_8, 8, 0, 1, 1);

        stackedWidget_cnt = new QStackedWidget(tab_2);
        stackedWidget_cnt->setObjectName(QStringLiteral("stackedWidget_cnt"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(9);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(stackedWidget_cnt->sizePolicy().hasHeightForWidth());
        stackedWidget_cnt->setSizePolicy(sizePolicy6);

        gridLayout_4->addWidget(stackedWidget_cnt, 0, 1, 10, 1);


        horizontalLayout_5->addLayout(gridLayout_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 20, 421, 16));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 90, 61, 16));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 130, 61, 16));
        lineEdit_decimal = new QLineEdit(tab_3);
        lineEdit_decimal->setObjectName(QStringLiteral("lineEdit_decimal"));
        lineEdit_decimal->setGeometry(QRect(150, 90, 171, 21));
        lineEdit_hex = new QLineEdit(tab_3);
        lineEdit_hex->setObjectName(QStringLiteral("lineEdit_hex"));
        lineEdit_hex->setGeometry(QRect(150, 130, 171, 21));
        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(90, 50, 281, 21));
        radioButton_bighead = new QRadioButton(widget_3);
        radioButton_bighead->setObjectName(QStringLiteral("radioButton_bighead"));
        radioButton_bighead->setGeometry(QRect(140, 0, 115, 19));
        radioButton_smallhead = new QRadioButton(widget_3);
        radioButton_smallhead->setObjectName(QStringLiteral("radioButton_smallhead"));
        radioButton_smallhead->setGeometry(QRect(10, 0, 115, 19));
        tabWidget->addTab(tab_3, QString());
        splitter->addWidget(tabWidget);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_show = new QCheckBox(widget);
        checkBox_show->setObjectName(QStringLiteral("checkBox_show"));

        horizontalLayout_2->addWidget(checkBox_show);

        comboBox_encode = new QComboBox(widget);
        comboBox_encode->setObjectName(QStringLiteral("comboBox_encode"));
        comboBox_encode->setMinimumSize(QSize(30, 0));
        comboBox_encode->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_2->addWidget(comboBox_encode);

        pushButton_check = new QPushButton(widget);
        pushButton_check->setObjectName(QStringLiteral("pushButton_check"));

        horizontalLayout_2->addWidget(pushButton_check);

        lineEdit_check = new QLineEdit(widget);
        lineEdit_check->setObjectName(QStringLiteral("lineEdit_check"));
        lineEdit_check->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEdit_check);

        pushButton_clear_rvc = new QPushButton(widget);
        pushButton_clear_rvc->setObjectName(QStringLiteral("pushButton_clear_rvc"));
        pushButton_clear_rvc->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(pushButton_clear_rvc);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        splitter->addWidget(widget);
        textEdit_Send = new QTextEdit(splitter);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(2);
        sizePolicy7.setHeightForWidth(textEdit_Send->sizePolicy().hasHeightForWidth());
        textEdit_Send->setSizePolicy(sizePolicy7);
        splitter->addWidget(textEdit_Send);
        splitter_2->addWidget(splitter);

        horizontalLayout_3->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1107, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


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
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\270\270\347\224\250\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_clear_send->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201", Q_NULLPTR));
        checkBox_DTR->setText(QApplication::translate("MainWindow", "DTR", Q_NULLPTR));
        checkBox_RTS->setText(QApplication::translate("MainWindow", "RTS", Q_NULLPTR));
        checkBox_change_line->setText(QApplication::translate("MainWindow", "\345\270\247\346\215\242\350\241\214", Q_NULLPTR));
        checkBox_show_send->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\346\223\215\344\275\234", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215(\351\273\230\350\256\244\345\275\223\345\211\215\346\227\266\351\227\264)\357\274\232", Q_NULLPTR));
        checkBox_savefile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_opendir->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\256\345\275\225", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\256\232\346\227\266\345\231\250", Q_NULLPTR));
        checkBox_enter->setText(QApplication::translate("MainWindow", "\345\233\236\350\275\246", Q_NULLPTR));
        checkBox_fixtime->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\345\217\221\351\200\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\345\221\250\346\234\237Ms", Q_NULLPTR));
        lineEdit_fixtime_ms->setText(QApplication::translate("MainWindow", "1000", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        radioButton_biaozhun->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "\350\277\233\345\210\266", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("MainWindow", "\345\244\247\345\206\231", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", Q_NULLPTR));
        radioButton_7->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", Q_NULLPTR));
        radioButton_9->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("MainWindow", "\345\244\207\347\224\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "IEEE 754\346\265\256\347\202\271\346\225\260\345\215\201\345\205\255\350\277\233\345\210\266\347\233\270\344\272\222\350\275\254\346\215\242(32\344\275\215,\345\233\233\345\255\227\350\212\202,\345\215\225\347\262\276\345\272\246)", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", " 10\350\277\233\345\210\266", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", " 16\350\277\233\345\210\266", Q_NULLPTR));
        radioButton_bighead->setText(QApplication::translate("MainWindow", " \345\244\247\347\253\257\346\240\274\345\274\217", Q_NULLPTR));
        radioButton_smallhead->setText(QApplication::translate("MainWindow", " \345\260\217\347\253\257\346\240\274\345\274\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\351\241\265", Q_NULLPTR));
        checkBox_show->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\216\245\346\224\266", Q_NULLPTR));
        comboBox_encode->clear();
        comboBox_encode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ASCII", Q_NULLPTR)
         << QApplication::translate("MainWindow", "UTF-8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Hex", Q_NULLPTR)
        );
        pushButton_check->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214", Q_NULLPTR));
        pushButton_clear_rvc->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
