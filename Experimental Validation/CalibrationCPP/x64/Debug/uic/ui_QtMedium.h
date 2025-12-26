/********************************************************************************
** Form generated from reading UI file 'QtMedium.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMEDIUM_H
#define UI_QTMEDIUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtMediumClass
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label1_2;
    QLineEdit *concentration;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label1_3;
    QLabel *label_water_3;
    QPushButton *Do_acohol;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label1;
    QLineEdit *water_vol;

    void setupUi(QWidget *QtMediumClass)
    {
        if (QtMediumClass->objectName().isEmpty())
            QtMediumClass->setObjectName(QString::fromUtf8("QtMediumClass"));
        QtMediumClass->resize(530, 159);
        layoutWidget = new QWidget(QtMediumClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 30, 254, 43));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label1_2 = new QLabel(layoutWidget);
        label1_2->setObjectName(QString::fromUtf8("label1_2"));
        label1_2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label1_2);

        concentration = new QLineEdit(layoutWidget);
        concentration->setObjectName(QString::fromUtf8("concentration"));
        concentration->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(concentration);

        layoutWidget_2 = new QWidget(QtMediumClass);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(220, 100, 222, 37));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label1_3 = new QLabel(layoutWidget_2);
        label1_3->setObjectName(QString::fromUtf8("label1_3"));
        label1_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label1_3);

        label_water_3 = new QLabel(layoutWidget_2);
        label_water_3->setObjectName(QString::fromUtf8("label_water_3"));
        label_water_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0,0,0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label_water_3);

        Do_acohol = new QPushButton(QtMediumClass);
        Do_acohol->setObjectName(QString::fromUtf8("Do_acohol"));
        Do_acohol->setGeometry(QRect(50, 100, 141, 41));
        Do_acohol->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        layoutWidget_3 = new QWidget(QtMediumClass);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 30, 211, 43));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(layoutWidget_3);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout->addWidget(label1);

        water_vol = new QLineEdit(layoutWidget_3);
        water_vol->setObjectName(QString::fromUtf8("water_vol"));
        water_vol->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        water_vol->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(water_vol);


        retranslateUi(QtMediumClass);

        QMetaObject::connectSlotsByName(QtMediumClass);
    } // setupUi

    void retranslateUi(QWidget *QtMediumClass)
    {
        QtMediumClass->setWindowTitle(QCoreApplication::translate("QtMediumClass", "QtMedium", nullptr));
        label1_2->setText(QCoreApplication::translate("QtMediumClass", "\347\233\256\346\240\207\346\265\223\345\272\246(%)\357\274\232", nullptr));
        label1_3->setText(QCoreApplication::translate("QtMediumClass", "\351\205\222\347\262\276(ml)\357\274\232", nullptr));
        label_water_3->setText(QString());
        Do_acohol->setText(QCoreApplication::translate("QtMediumClass", "\350\256\241\347\256\227", nullptr));
        label1->setText(QCoreApplication::translate("QtMediumClass", "\346\260\264(ml)\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtMediumClass: public Ui_QtMediumClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMEDIUM_H
