/********************************************************************************
** Form generated from reading UI file 'SysSet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSSET_H
#define UI_SYSSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysSet
{
public:
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *cB_port;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pB_connect;
    QTextBrowser *tB_Info;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *sB_cameraPos;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *sB_cameraSew;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QSpinBox *sB_speedPulLead;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QSpinBox *sB_speedRolling;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QSpinBox *sB_speedTurnTable;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QSpinBox *sB_speedVibration;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pB_set;

    void setupUi(QWidget *SysSet)
    {
        if (SysSet->objectName().isEmpty())
            SysSet->setObjectName(QStringLiteral("SysSet"));
        SysSet->resize(538, 440);
        verticalLayout_10 = new QVBoxLayout(SysSet);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cB_port = new QComboBox(SysSet);
        cB_port->setObjectName(QStringLiteral("cB_port"));

        horizontalLayout_4->addWidget(cB_port);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pB_connect = new QPushButton(SysSet);
        pB_connect->setObjectName(QStringLiteral("pB_connect"));

        horizontalLayout_4->addWidget(pB_connect);


        verticalLayout_9->addLayout(horizontalLayout_4);

        tB_Info = new QTextBrowser(SysSet);
        tB_Info->setObjectName(QStringLiteral("tB_Info"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tB_Info->sizePolicy().hasHeightForWidth());
        tB_Info->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(tB_Info);


        horizontalLayout_5->addLayout(verticalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SysSet);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        sB_cameraPos = new QSpinBox(SysSet);
        sB_cameraPos->setObjectName(QStringLiteral("sB_cameraPos"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sB_cameraPos->sizePolicy().hasHeightForWidth());
        sB_cameraPos->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("AcadEref"));
        font1.setPointSize(20);
        sB_cameraPos->setFont(font1);
        sB_cameraPos->setValue(1);

        verticalLayout->addWidget(sB_cameraPos);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(SysSet);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        sB_cameraSew = new QSpinBox(SysSet);
        sB_cameraSew->setObjectName(QStringLiteral("sB_cameraSew"));
        sizePolicy1.setHeightForWidth(sB_cameraSew->sizePolicy().hasHeightForWidth());
        sB_cameraSew->setSizePolicy(sizePolicy1);
        sB_cameraSew->setFont(font1);
        sB_cameraSew->setValue(2);

        verticalLayout_2->addWidget(sB_cameraSew);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_5->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_5 = new QLabel(SysSet);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_5);

        sB_speedPulLead = new QSpinBox(SysSet);
        sB_speedPulLead->setObjectName(QStringLiteral("sB_speedPulLead"));
        sizePolicy1.setHeightForWidth(sB_speedPulLead->sizePolicy().hasHeightForWidth());
        sB_speedPulLead->setSizePolicy(sizePolicy1);
        sB_speedPulLead->setFont(font1);

        verticalLayout_6->addWidget(sB_speedPulLead);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(SysSet);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_4);

        sB_speedRolling = new QSpinBox(SysSet);
        sB_speedRolling->setObjectName(QStringLiteral("sB_speedRolling"));
        sizePolicy1.setHeightForWidth(sB_speedRolling->sizePolicy().hasHeightForWidth());
        sB_speedRolling->setSizePolicy(sizePolicy1);
        sB_speedRolling->setFont(font1);

        verticalLayout_5->addWidget(sB_speedRolling);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(SysSet);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        sB_speedTurnTable = new QSpinBox(SysSet);
        sB_speedTurnTable->setObjectName(QStringLiteral("sB_speedTurnTable"));
        sizePolicy1.setHeightForWidth(sB_speedTurnTable->sizePolicy().hasHeightForWidth());
        sB_speedTurnTable->setSizePolicy(sizePolicy1);
        sB_speedTurnTable->setFont(font1);

        verticalLayout_4->addWidget(sB_speedTurnTable);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_6 = new QLabel(SysSet);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_6);

        sB_speedVibration = new QSpinBox(SysSet);
        sB_speedVibration->setObjectName(QStringLiteral("sB_speedVibration"));
        sizePolicy1.setHeightForWidth(sB_speedVibration->sizePolicy().hasHeightForWidth());
        sB_speedVibration->setSizePolicy(sizePolicy1);
        sB_speedVibration->setFont(font1);

        verticalLayout_7->addWidget(sB_speedVibration);


        horizontalLayout_3->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pB_set = new QPushButton(SysSet);
        pB_set->setObjectName(QStringLiteral("pB_set"));
        pB_set->setFont(font);

        horizontalLayout_2->addWidget(pB_set);


        verticalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_8);


        verticalLayout_10->addLayout(verticalLayout_3);


        retranslateUi(SysSet);

        QMetaObject::connectSlotsByName(SysSet);
    } // setupUi

    void retranslateUi(QWidget *SysSet)
    {
        SysSet->setWindowTitle(QApplication::translate("SysSet", "SysSet", Q_NULLPTR));
        pB_connect->setText(QApplication::translate("SysSet", "\351\223\276\346\216\245", Q_NULLPTR));
        label->setText(QApplication::translate("SysSet", "\346\255\243\345\217\215\346\243\200\346\265\213\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("SysSet", "\347\213\255\347\274\235\346\243\200\346\265\213\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_5->setText(QApplication::translate("SysSet", "\351\223\205\347\232\256\346\216\250\350\277\233\350\260\203\351\200\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("SysSet", "\345\215\267\350\243\271\350\260\203\351\200\237", Q_NULLPTR));
        label_3->setText(QApplication::translate("SysSet", "\350\275\254\347\233\230\350\260\203\351\200\237", Q_NULLPTR));
        label_6->setText(QApplication::translate("SysSet", "\346\214\257\345\212\250\350\260\203\351\242\221", Q_NULLPTR));
        pB_set->setText(QApplication::translate("SysSet", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SysSet: public Ui_SysSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSSET_H
