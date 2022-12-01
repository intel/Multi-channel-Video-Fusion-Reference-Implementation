/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <playerwindow.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *fromLineEdit_1;
    QPushButton *fileOpenButton_1;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *fromLineEdit_2;
    QPushButton *fileOpenButton_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *fromLineEdit_3;
    QPushButton *fileOpenButton_3;
    QRadioButton *radioButton;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fromLineEdit;
    QPushButton *fileOpenButton;
    QPushButton *streamButton;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *toLineEdit;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *TimeinSecond;
    QLabel *label_7;
    PlayerWindow *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *StatusLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *ClearButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(650, 0));
        Dialog->setWindowOpacity(1.000000000000000);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(Dialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(150);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(0, 0));
        listWidget->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(listWidget, 0, 0, 2, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setMinimumSize(QSize(100, 23));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        fromLineEdit_1 = new QLineEdit(Dialog);
        fromLineEdit_1->setObjectName(QString::fromUtf8("fromLineEdit_1"));
        fromLineEdit_1->setMinimumSize(QSize(400, 0));

        horizontalLayout_2->addWidget(fromLineEdit_1);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        fileOpenButton_1 = new QPushButton(Dialog);
        fileOpenButton_1->setObjectName(QString::fromUtf8("fileOpenButton_1"));

        horizontalLayout_5->addWidget(fileOpenButton_1);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(107, 23));

        horizontalLayout_3->addWidget(label_3);

        fromLineEdit_2 = new QLineEdit(Dialog);
        fromLineEdit_2->setObjectName(QString::fromUtf8("fromLineEdit_2"));

        horizontalLayout_3->addWidget(fromLineEdit_2);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        fileOpenButton_2 = new QPushButton(Dialog);
        fileOpenButton_2->setObjectName(QString::fromUtf8("fileOpenButton_2"));

        horizontalLayout_6->addWidget(fileOpenButton_2);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 2, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(107, 23));

        horizontalLayout_8->addWidget(label_4);

        fromLineEdit_3 = new QLineEdit(Dialog);
        fromLineEdit_3->setObjectName(QString::fromUtf8("fromLineEdit_3"));

        horizontalLayout_8->addWidget(fromLineEdit_3);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        fileOpenButton_3 = new QPushButton(Dialog);
        fileOpenButton_3->setObjectName(QString::fromUtf8("fileOpenButton_3"));

        horizontalLayout_7->addWidget(fileOpenButton_3);


        gridLayout_2->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        radioButton = new QRadioButton(Dialog);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setMinimumSize(QSize(200, 0));

        gridLayout_2->addWidget(radioButton, 0, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(107, 23));

        horizontalLayout->addWidget(label);

        fromLineEdit = new QLineEdit(Dialog);
        fromLineEdit->setObjectName(QString::fromUtf8("fromLineEdit"));
        fromLineEdit->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(4);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(fromLineEdit->sizePolicy().hasHeightForWidth());
        fromLineEdit->setSizePolicy(sizePolicy4);
        fromLineEdit->setMinimumSize(QSize(400, 0));

        horizontalLayout->addWidget(fromLineEdit);


        horizontalLayout_4->addLayout(horizontalLayout);

        fileOpenButton = new QPushButton(Dialog);
        fileOpenButton->setObjectName(QString::fromUtf8("fileOpenButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(fileOpenButton->sizePolicy().hasHeightForWidth());
        fileOpenButton->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(fileOpenButton);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        streamButton = new QPushButton(Dialog);
        streamButton->setObjectName(QString::fromUtf8("streamButton"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(streamButton->sizePolicy().hasHeightForWidth());
        streamButton->setSizePolicy(sizePolicy6);
        streamButton->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(streamButton, 3, 1, 1, 4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        toLineEdit = new QLineEdit(Dialog);
        toLineEdit->setObjectName(QString::fromUtf8("toLineEdit"));

        horizontalLayout_12->addWidget(toLineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_12);

        startButton = new QPushButton(Dialog);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy7);
        startButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_11->addWidget(startButton);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_11, 2, 2, 1, 3);

        TimeinSecond = new QLineEdit(Dialog);
        TimeinSecond->setObjectName(QString::fromUtf8("TimeinSecond"));

        gridLayout_2->addWidget(TimeinSecond, 0, 4, 1, 1);

        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setMinimumSize(QSize(150, 0));

        gridLayout_2->addWidget(label_7, 0, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 2);

        widget = new PlayerWindow(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget, 1, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        StatusLabel = new QLabel(Dialog);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
        StatusLabel->setMinimumSize(QSize(100, 23));

        horizontalLayout_9->addWidget(StatusLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        ClearButton = new QPushButton(Dialog);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setMinimumSize(QSize(100, 0));

        horizontalLayout_9->addWidget(ClearButton);


        gridLayout->addLayout(horizontalLayout_9, 2, 1, 1, 2);

#if QT_CONFIG(shortcut)
        label_2->setBuddy(fromLineEdit);
        label_3->setBuddy(fromLineEdit);
        label_5->setBuddy(toLineEdit);
        label_4->setBuddy(fromLineEdit);
        label->setBuddy(fromLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\345\233\276\345\203\217\350\236\215\345\220\210\346\274\224\347\244\272Demo", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Or Choose", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\347\211\271\345\206\231\357\274\210\346\212\240\345\233\276\357\274\211\345\217\257\351\200\211:", nullptr));
        fileOpenButton_1->setText(QCoreApplication::translate("Dialog", "Open...", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\350\264\264\347\211\207\357\274\210\345\217\257\351\200\211\357\274\211:", nullptr));
        fileOpenButton_2->setText(QCoreApplication::translate("Dialog", "Open...", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "\346\226\207\344\273\266\344\277\235\345\255\230\344\270\272\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\350\203\214\346\231\257:", nullptr));
        fileOpenButton_3->setText(QCoreApplication::translate("Dialog", "Open...", nullptr));
        radioButton->setText(QCoreApplication::translate("Dialog", "Camera", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\345\211\215\346\231\257\357\274\210\346\212\240\345\233\276\357\274\211:", nullptr));
        fileOpenButton->setText(QCoreApplication::translate("Dialog", "Open...", nullptr));
        streamButton->setText(QCoreApplication::translate("Dialog", "\346\216\250\346\265\201", nullptr));
        startButton->setText(QCoreApplication::translate("Dialog", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "Time in Seconds:[1-9999]", nullptr));
        StatusLabel->setText(QCoreApplication::translate("Dialog", "\346\211\247\350\241\214\347\212\266\346\200\201:", nullptr));
        ClearButton->setText(QCoreApplication::translate("Dialog", "Clear All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
