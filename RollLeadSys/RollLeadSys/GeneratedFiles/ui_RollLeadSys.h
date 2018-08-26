/********************************************************************************
** Form generated from reading UI file 'RollLeadSys.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLLLEADSYS_H
#define UI_ROLLLEADSYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RollLeadSysClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_10;
    QLabel *label;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *lb_Camera1;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_Infoshow;
    QSpacerItem *horizontalSpacer;
    QPushButton *pB_start1;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lb_Camera2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_Infoshow2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pB_start2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLCDNumber *lN_Counter;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QPushButton *pB_vibration;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QPushButton *pB_rolling;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_5;
    QPushButton *pB_Filter;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pB_Turntable;
    QMenuBar *menuBar;
    QMenu *m_Set;
    QMenu *m_Info;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RollLeadSysClass)
    {
        if (RollLeadSysClass->objectName().isEmpty())
            RollLeadSysClass->setObjectName(QStringLiteral("RollLeadSysClass"));
        RollLeadSysClass->resize(1205, 599);
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        RollLeadSysClass->setFont(font);
        centralWidget = new QWidget(RollLeadSysClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_9 = new QHBoxLayout(centralWidget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("AcadEref"));
        font1.setPointSize(18);
        label->setFont(font1);
        label->setMouseTracking(false);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_Camera1 = new QLabel(groupBox);
        lb_Camera1->setObjectName(QStringLiteral("lb_Camera1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lb_Camera1->sizePolicy().hasHeightForWidth());
        lb_Camera1->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(lb_Camera1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lb_Infoshow = new QLabel(groupBox);
        lb_Infoshow->setObjectName(QStringLiteral("lb_Infoshow"));

        horizontalLayout->addWidget(lb_Infoshow);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pB_start1 = new QPushButton(groupBox);
        pB_start1->setObjectName(QStringLiteral("pB_start1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pB_start1->sizePolicy().hasHeightForWidth());
        pB_start1->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pB_start1);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lb_Camera2 = new QLabel(groupBox_2);
        lb_Camera2->setObjectName(QStringLiteral("lb_Camera2"));
        sizePolicy1.setHeightForWidth(lb_Camera2->sizePolicy().hasHeightForWidth());
        lb_Camera2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lb_Camera2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lb_Infoshow2 = new QLabel(groupBox_2);
        lb_Infoshow2->setObjectName(QStringLiteral("lb_Infoshow2"));

        horizontalLayout_2->addWidget(lb_Infoshow2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pB_start2 = new QPushButton(groupBox_2);
        pB_start2->setObjectName(QStringLiteral("pB_start2"));
        sizePolicy2.setHeightForWidth(pB_start2->sizePolicy().hasHeightForWidth());
        pB_start2->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pB_start2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_7->addWidget(groupBox_2);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lN_Counter = new QLCDNumber(groupBox_3);
        lN_Counter->setObjectName(QStringLiteral("lN_Counter"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lN_Counter->sizePolicy().hasHeightForWidth());
        lN_Counter->setSizePolicy(sizePolicy4);
        lN_Counter->setFrameShape(QFrame::Box);
        lN_Counter->setFrameShadow(QFrame::Raised);
        lN_Counter->setLineWidth(2);
        lN_Counter->setMidLineWidth(4);
        lN_Counter->setSmallDecimalPoint(false);
        lN_Counter->setSegmentStyle(QLCDNumber::Flat);
        lN_Counter->setProperty("value", QVariant(0));

        verticalLayout_3->addWidget(lN_Counter);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMaximumSize(QSize(300, 16777215));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);

        pB_vibration = new QPushButton(groupBox_4);
        pB_vibration->setObjectName(QStringLiteral("pB_vibration"));

        verticalLayout_6->addWidget(pB_vibration);


        horizontalLayout_4->addLayout(verticalLayout_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        pB_rolling = new QPushButton(groupBox_4);
        pB_rolling->setObjectName(QStringLiteral("pB_rolling"));

        verticalLayout_7->addWidget(pB_rolling);


        horizontalLayout_4->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_5);

        pB_Filter = new QPushButton(groupBox_4);
        pB_Filter->setObjectName(QStringLiteral("pB_Filter"));

        verticalLayout_11->addWidget(pB_Filter);


        horizontalLayout_5->addLayout(verticalLayout_11);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pB_Turntable = new QPushButton(groupBox_4);
        pB_Turntable->setObjectName(QStringLiteral("pB_Turntable"));

        horizontalLayout_3->addWidget(pB_Turntable);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_5);


        verticalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout_6->addLayout(verticalLayout_9);


        verticalLayout_5->addWidget(groupBox_4);


        horizontalLayout_8->addLayout(verticalLayout_5);


        verticalLayout_10->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_10);

        RollLeadSysClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RollLeadSysClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1205, 26));
        m_Set = new QMenu(menuBar);
        m_Set->setObjectName(QStringLiteral("m_Set"));
        m_Info = new QMenu(menuBar);
        m_Info->setObjectName(QStringLiteral("m_Info"));
        RollLeadSysClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RollLeadSysClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RollLeadSysClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RollLeadSysClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RollLeadSysClass->setStatusBar(statusBar);

        menuBar->addAction(m_Set->menuAction());
        menuBar->addAction(m_Info->menuAction());

        retranslateUi(RollLeadSysClass);

        QMetaObject::connectSlotsByName(RollLeadSysClass);
    } // setupUi

    void retranslateUi(QMainWindow *RollLeadSysClass)
    {
        RollLeadSysClass->setWindowTitle(QApplication::translate("RollLeadSysClass", "RollLeadSys", Q_NULLPTR));
        label->setText(QApplication::translate("RollLeadSysClass", "\351\223\205\347\232\256\345\215\267\350\243\271\347\263\273\347\273\237", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RollLeadSysClass", "\346\255\243\345\217\215\346\243\200\346\265\213", Q_NULLPTR));
        lb_Camera1->setText(QString());
        lb_Infoshow->setText(QString());
        pB_start1->setText(QApplication::translate("RollLeadSysClass", "\345\220\257\347\224\250", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("RollLeadSysClass", "\347\213\255\347\274\235\346\243\200\346\265\213", Q_NULLPTR));
        lb_Camera2->setText(QString());
        lb_Infoshow2->setText(QString());
        pB_start2->setText(QApplication::translate("RollLeadSysClass", "\345\220\257\347\224\250", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("RollLeadSysClass", "\350\256\241\346\225\260", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("RollLeadSysClass", "\346\216\247\345\210\266", Q_NULLPTR));
        label_3->setText(QApplication::translate("RollLeadSysClass", "\346\214\257\345\212\250\347\263\273\347\273\237", Q_NULLPTR));
        pB_vibration->setText(QApplication::translate("RollLeadSysClass", "\345\220\257\345\212\250", Q_NULLPTR));
        label_4->setText(QApplication::translate("RollLeadSysClass", "\345\215\267\350\243\271\347\263\273\347\273\237", Q_NULLPTR));
        pB_rolling->setText(QApplication::translate("RollLeadSysClass", "\345\220\257\345\212\250", Q_NULLPTR));
        label_5->setText(QApplication::translate("RollLeadSysClass", "\350\277\207\346\273\244\347\263\273\347\273\237", Q_NULLPTR));
        pB_Filter->setText(QApplication::translate("RollLeadSysClass", "\345\220\257\345\212\250", Q_NULLPTR));
        label_2->setText(QApplication::translate("RollLeadSysClass", "\350\275\254\347\233\230\350\275\254\345\212\250\346\216\222\347\251\272", Q_NULLPTR));
        pB_Turntable->setText(QApplication::translate("RollLeadSysClass", "\351\241\272\346\227\266\351\222\210", Q_NULLPTR));
        m_Set->setTitle(QApplication::translate("RollLeadSysClass", "&\350\256\276\347\275\256", Q_NULLPTR));
        m_Info->setTitle(QApplication::translate("RollLeadSysClass", "&\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RollLeadSysClass: public Ui_RollLeadSysClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLLLEADSYS_H
