/********************************************************************************
** Form generated from reading UI file 'CalibrationApp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONAPP_H
#define UI_CALIBRATIONAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibrationAppClass
{
public:
    QWidget *centralWidget;
    QPushButton *point_picker;
    QTableWidget *tableWidget;
    QFrame *frame;
    QPushButton *Do_cal;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QPushButton *Do_calibration;
    QPushButton *Seg_Reader;
    QPushButton *US_picker;
    QLabel *label_error;
    QLabel *label_num;
    QLabel *pointnum;
    QLabel *meanerror;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *connect_ndi;
    QLabel *probe_DRO;
    QLabel *US_DRO;
    QLabel *M_DRO;
    QFrame *frame_2;
    QPushButton *Trans_Output;
    QPushButton *Trans_Reader;
    QLabel *label_num_2;
    QPushButton *saveresult;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CalibrationAppClass)
    {
        if (CalibrationAppClass->objectName().isEmpty())
            CalibrationAppClass->setObjectName(QString::fromUtf8("CalibrationAppClass"));
        CalibrationAppClass->resize(1079, 771);
        CalibrationAppClass->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 184, 184);"));
        centralWidget = new QWidget(CalibrationAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        point_picker = new QPushButton(centralWidget);
        point_picker->setObjectName(QString::fromUtf8("point_picker"));
        point_picker->setGeometry(QRect(90, 70, 151, 41));
        point_picker->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 120, 301, 311));
        tableWidget->setColumnCount(3);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 381, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Do_cal = new QPushButton(frame);
        Do_cal->setObjectName(QString::fromUtf8("Do_cal"));
        Do_cal->setGeometry(QRect(0, 0, 141, 41));
        Do_cal->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem9);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(370, 120, 691, 311));
        tableWidget_3 = new QTableWidget(centralWidget);
        if (tableWidget_3->columnCount() < 4)
            tableWidget_3->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        if (tableWidget_3->rowCount() < 4)
            tableWidget_3->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(3, __qtablewidgetitem17);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(260, 560, 421, 151));
        Do_calibration = new QPushButton(centralWidget);
        Do_calibration->setObjectName(QString::fromUtf8("Do_calibration"));
        Do_calibration->setGeometry(QRect(70, 610, 141, 41));
        Do_calibration->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        Seg_Reader = new QPushButton(centralWidget);
        Seg_Reader->setObjectName(QString::fromUtf8("Seg_Reader"));
        Seg_Reader->setGeometry(QRect(70, 560, 141, 41));
        Seg_Reader->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        US_picker = new QPushButton(centralWidget);
        US_picker->setObjectName(QString::fromUtf8("US_picker"));
        US_picker->setGeometry(QRect(630, 70, 171, 41));
        US_picker->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_error = new QLabel(centralWidget);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setGeometry(QRect(700, 630, 141, 21));
        label_error->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_num = new QLabel(centralWidget);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(720, 580, 111, 21));
        label_num->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pointnum = new QLabel(centralWidget);
        pointnum->setObjectName(QString::fromUtf8("pointnum"));
        pointnum->setGeometry(QRect(840, 580, 151, 30));
        pointnum->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0,0,0);\n"
"background-color: rgb(255, 255, 255);"));
        meanerror = new QLabel(centralWidget);
        meanerror->setObjectName(QString::fromUtf8("meanerror"));
        meanerror->setGeometry(QRect(840, 630, 151, 30));
        meanerror->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0,0,0);\n"
"background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 0, 341, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        connect_ndi = new QPushButton(layoutWidget);
        connect_ndi->setObjectName(QString::fromUtf8("connect_ndi"));
        connect_ndi->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 101);\n"
"font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(connect_ndi);

        probe_DRO = new QLabel(layoutWidget);
        probe_DRO->setObjectName(QString::fromUtf8("probe_DRO"));
        probe_DRO->setMinimumSize(QSize(20, 20));
        probe_DRO->setMaximumSize(QSize(60, 20));
        probe_DRO->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 0, 0);\n"
"font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(probe_DRO);

        US_DRO = new QLabel(layoutWidget);
        US_DRO->setObjectName(QString::fromUtf8("US_DRO"));
        US_DRO->setMinimumSize(QSize(20, 20));
        US_DRO->setMaximumSize(QSize(60, 20));
        US_DRO->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 0, 0);\n"
"font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(US_DRO);

        M_DRO = new QLabel(layoutWidget);
        M_DRO->setObjectName(QString::fromUtf8("M_DRO"));
        M_DRO->setMinimumSize(QSize(20, 20));
        M_DRO->setMaximumSize(QSize(60, 20));
        M_DRO->setStyleSheet(QString::fromUtf8("background-color: rgb(182, 0, 0);\n"
"font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(M_DRO);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(380, 440, 681, 80));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Trans_Output = new QPushButton(frame_2);
        Trans_Output->setObjectName(QString::fromUtf8("Trans_Output"));
        Trans_Output->setGeometry(QRect(0, 10, 141, 41));
        Trans_Output->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        Trans_Reader = new QPushButton(frame_2);
        Trans_Reader->setObjectName(QString::fromUtf8("Trans_Reader"));
        Trans_Reader->setGeometry(QRect(170, 10, 141, 41));
        Trans_Reader->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_num_2 = new QLabel(frame_2);
        label_num_2->setObjectName(QString::fromUtf8("label_num_2"));
        label_num_2->setGeometry(QRect(340, 10, 331, 51));
        label_num_2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        saveresult = new QPushButton(centralWidget);
        saveresult->setObjectName(QString::fromUtf8("saveresult"));
        saveresult->setGeometry(QRect(70, 660, 141, 41));
        saveresult->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        CalibrationAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CalibrationAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1079, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CalibrationAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CalibrationAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CalibrationAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CalibrationAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CalibrationAppClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(CalibrationAppClass);

        QMetaObject::connectSlotsByName(CalibrationAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *CalibrationAppClass)
    {
        CalibrationAppClass->setWindowTitle(QCoreApplication::translate("CalibrationAppClass", "CalibrationApp", nullptr));
        point_picker->setText(QCoreApplication::translate("CalibrationAppClass", "\345\274\200\345\220\257\346\250\241\345\236\213\347\202\271\346\213\276\345\217\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CalibrationAppClass", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CalibrationAppClass", "y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CalibrationAppClass", "z", nullptr));
        Do_cal->setText(QCoreApplication::translate("CalibrationAppClass", "\346\240\207\345\256\232\344\273\213\350\264\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CalibrationAppClass", "q0", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CalibrationAppClass", "qx", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CalibrationAppClass", "qy", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CalibrationAppClass", "qz", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CalibrationAppClass", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CalibrationAppClass", "y", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CalibrationAppClass", "z", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CalibrationAppClass", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CalibrationAppClass", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("CalibrationAppClass", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("CalibrationAppClass", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("CalibrationAppClass", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("CalibrationAppClass", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->verticalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("CalibrationAppClass", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->verticalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("CalibrationAppClass", "4", nullptr));
        Do_calibration->setText(QCoreApplication::translate("CalibrationAppClass", "\345\274\200\345\247\213\346\240\207\345\256\232", nullptr));
        Seg_Reader->setText(QCoreApplication::translate("CalibrationAppClass", "\350\257\273\345\217\226\345\210\206\345\211\262\346\225\260\346\215\256", nullptr));
        US_picker->setText(QCoreApplication::translate("CalibrationAppClass", "\345\274\200\345\220\257\350\266\205\345\243\260\345\233\276\345\203\217\346\213\276\345\217\226", nullptr));
        label_error->setText(QCoreApplication::translate("CalibrationAppClass", "\345\271\263\345\235\207\350\257\257\345\267\256(mm)\357\274\232", nullptr));
        label_num->setText(QCoreApplication::translate("CalibrationAppClass", "\346\240\207\345\256\232\347\202\271\344\270\252\346\225\260\357\274\232", nullptr));
        pointnum->setText(QCoreApplication::translate("CalibrationAppClass", "TextLabel", nullptr));
        meanerror->setText(QCoreApplication::translate("CalibrationAppClass", "TextLabel", nullptr));
        connect_ndi->setText(QCoreApplication::translate("CalibrationAppClass", "\350\277\236\346\216\245NDI", nullptr));
        probe_DRO->setText(QCoreApplication::translate("CalibrationAppClass", "Probe", nullptr));
        US_DRO->setText(QCoreApplication::translate("CalibrationAppClass", "   US", nullptr));
        M_DRO->setText(QCoreApplication::translate("CalibrationAppClass", "Model", nullptr));
        Trans_Output->setText(QCoreApplication::translate("CalibrationAppClass", "\345\257\274\345\207\272\345\247\277\346\200\201\346\225\260\346\215\256", nullptr));
        Trans_Reader->setText(QCoreApplication::translate("CalibrationAppClass", "\350\257\273\345\217\226\345\247\277\346\200\201\346\225\260\346\215\256", nullptr));
        label_num_2->setText(QCoreApplication::translate("CalibrationAppClass", "\346\217\220\347\244\272\357\274\232\344\270\215\351\207\207\351\233\206\345\233\276\345\203\217\346\227\266\357\274\214\345\217\257\347\233\264\346\216\245\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        saveresult->setText(QCoreApplication::translate("CalibrationAppClass", "\344\277\235\345\255\230\347\273\223\346\236\234", nullptr));
        menu->setTitle(QCoreApplication::translate("CalibrationAppClass", "\346\240\207\345\256\232\344\273\213\350\264\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalibrationAppClass: public Ui_CalibrationAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONAPP_H
