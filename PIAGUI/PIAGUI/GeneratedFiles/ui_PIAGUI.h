/********************************************************************************
** Form generated from reading UI file 'PIAGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIAGUI_H
#define UI_PIAGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "myopenglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_PIAGUIClass
{
public:
    QAction *OpenFile;
    QAction *actiongcur;
    QAction *actionLSPIA;
    QAction *actionSPARSE;
    QWidget *centralWidget;
    MyOpenGLWidget *widget;
    QLabel *medit;
    QLineEdit *DataNum;
    QLabel *medit_2;
    QLabel *label_4;
    QLineEdit *CtlNum;
    QLineEdit *FittingError;
    QRadioButton *PIAButton;
    QCheckBox *CtlPoints;
    QCheckBox *CtlPoly;
    QCheckBox *CurvaturePole;
    QCheckBox *BsplineCurve;
    QPushButton *OneStepIterate;
    QLabel *label;
    QRadioButton *LSPIAButton;
    QRadioButton *radioButton_3;
    QLineEdit *TargetError;
    QLabel *label_3;
    QCheckBox *DataPoints;
    QLabel *label_5;
    QLineEdit *PosNum;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *data;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PIAGUIClass)
    {
        if (PIAGUIClass->objectName().isEmpty())
            PIAGUIClass->setObjectName(QStringLiteral("PIAGUIClass"));
        PIAGUIClass->resize(1026, 703);
        OpenFile = new QAction(PIAGUIClass);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        actiongcur = new QAction(PIAGUIClass);
        actiongcur->setObjectName(QStringLiteral("actiongcur"));
        actionLSPIA = new QAction(PIAGUIClass);
        actionLSPIA->setObjectName(QStringLiteral("actionLSPIA"));
        actionSPARSE = new QAction(PIAGUIClass);
        actionSPARSE->setObjectName(QStringLiteral("actionSPARSE"));
        centralWidget = new QWidget(PIAGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyOpenGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-1, -1, 671, 671));
        medit = new QLabel(widget);
        medit->setObjectName(QStringLiteral("medit"));
        medit->setGeometry(QRect(10, 0, 101, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        medit->setFont(font);
        DataNum = new QLineEdit(widget);
        DataNum->setObjectName(QStringLiteral("DataNum"));
        DataNum->setEnabled(false);
        DataNum->setGeometry(QRect(110, 0, 91, 20));
        QFont font1;
        font1.setPointSize(10);
        DataNum->setFont(font1);
        DataNum->setStyleSheet(QStringLiteral("background:transparent;border-width:0;border-style:outset"));
        medit_2 = new QLabel(widget);
        medit_2->setObjectName(QStringLiteral("medit_2"));
        medit_2->setGeometry(QRect(10, 20, 101, 21));
        medit_2->setFont(font);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 40, 121, 16));
        label_4->setFont(font);
        CtlNum = new QLineEdit(widget);
        CtlNum->setObjectName(QStringLiteral("CtlNum"));
        CtlNum->setEnabled(false);
        CtlNum->setGeometry(QRect(110, 20, 101, 20));
        CtlNum->setFont(font1);
        CtlNum->setStyleSheet(QStringLiteral("background:transparent;border-width:0;border-style:outset"));
        FittingError = new QLineEdit(widget);
        FittingError->setObjectName(QStringLiteral("FittingError"));
        FittingError->setEnabled(false);
        FittingError->setGeometry(QRect(120, 40, 121, 20));
        FittingError->setFont(font1);
        FittingError->setStyleSheet(QStringLiteral("background:transparent;border-width:0;border-style:outset"));
        medit->raise();
        medit_2->raise();
        label_4->raise();
        FittingError->raise();
        CtlNum->raise();
        DataNum->raise();
        PIAButton = new QRadioButton(centralWidget);
        PIAButton->setObjectName(QStringLiteral("PIAButton"));
        PIAButton->setGeometry(QRect(690, 260, 121, 16));
        PIAButton->setFont(font1);
        PIAButton->setCheckable(true);
        PIAButton->setChecked(false);
        CtlPoints = new QCheckBox(centralWidget);
        CtlPoints->setObjectName(QStringLiteral("CtlPoints"));
        CtlPoints->setGeometry(QRect(690, 50, 141, 16));
        CtlPoints->setFont(font1);
        CtlPoints->setChecked(true);
        CtlPoly = new QCheckBox(centralWidget);
        CtlPoly->setObjectName(QStringLiteral("CtlPoly"));
        CtlPoly->setGeometry(QRect(860, 50, 131, 16));
        CtlPoly->setFont(font1);
        CtlPoly->setChecked(true);
        CurvaturePole = new QCheckBox(centralWidget);
        CurvaturePole->setObjectName(QStringLiteral("CurvaturePole"));
        CurvaturePole->setGeometry(QRect(690, 110, 131, 16));
        CurvaturePole->setFont(font1);
        CurvaturePole->setChecked(false);
        BsplineCurve = new QCheckBox(centralWidget);
        BsplineCurve->setObjectName(QStringLiteral("BsplineCurve"));
        BsplineCurve->setGeometry(QRect(860, 80, 121, 16));
        BsplineCurve->setFont(font1);
        BsplineCurve->setChecked(true);
        OneStepIterate = new QPushButton(centralWidget);
        OneStepIterate->setObjectName(QStringLiteral("OneStepIterate"));
        OneStepIterate->setGeometry(QRect(680, 520, 201, 23));
        OneStepIterate->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 10, 121, 16));
        label->setFont(font);
        LSPIAButton = new QRadioButton(centralWidget);
        LSPIAButton->setObjectName(QStringLiteral("LSPIAButton"));
        LSPIAButton->setGeometry(QRect(690, 300, 89, 16));
        LSPIAButton->setFont(font1);
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(690, 470, 89, 16));
        radioButton_3->setFont(font1);
        TargetError = new QLineEdit(centralWidget);
        TargetError->setObjectName(QStringLiteral("TargetError"));
        TargetError->setEnabled(true);
        TargetError->setGeometry(QRect(860, 180, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(690, 180, 121, 16));
        label_3->setFont(font);
        DataPoints = new QCheckBox(centralWidget);
        DataPoints->setObjectName(QStringLiteral("DataPoints"));
        DataPoints->setGeometry(QRect(690, 80, 141, 16));
        DataPoints->setFont(font1);
        DataPoints->setChecked(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(690, 140, 121, 16));
        label_5->setFont(font);
        PosNum = new QLineEdit(centralWidget);
        PosNum->setObjectName(QStringLiteral("PosNum"));
        PosNum->setEnabled(true);
        PosNum->setGeometry(QRect(860, 140, 113, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(980, 140, 21, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_6->setFont(font2);
        PIAGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PIAGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1026, 23));
        file = new QMenu(menuBar);
        file->setObjectName(QStringLiteral("file"));
        data = new QMenu(menuBar);
        data->setObjectName(QStringLiteral("data"));
        PIAGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PIAGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PIAGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PIAGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PIAGUIClass->setStatusBar(statusBar);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(data->menuAction());
        file->addAction(OpenFile);
        data->addAction(actiongcur);
        data->addAction(actionLSPIA);
        data->addAction(actionSPARSE);

        retranslateUi(PIAGUIClass);

        QMetaObject::connectSlotsByName(PIAGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *PIAGUIClass)
    {
        PIAGUIClass->setWindowTitle(QApplication::translate("PIAGUIClass", "PIAGUI", Q_NULLPTR));
        OpenFile->setText(QApplication::translate("PIAGUIClass", "Open", Q_NULLPTR));
        actiongcur->setText(QApplication::translate("PIAGUIClass", "g.cur", Q_NULLPTR));
        actionLSPIA->setText(QApplication::translate("PIAGUIClass", "LSPIA", Q_NULLPTR));
        actionSPARSE->setText(QApplication::translate("PIAGUIClass", "SPARSE", Q_NULLPTR));
        medit->setText(QApplication::translate("PIAGUIClass", "Data Number:", Q_NULLPTR));
        DataNum->setText(QString());
        medit_2->setText(QApplication::translate("PIAGUIClass", "Ctl  Number:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PIAGUIClass", "Fitting Error:", Q_NULLPTR));
        CtlNum->setText(QString());
        FittingError->setText(QString());
        PIAButton->setText(QApplication::translate("PIAGUIClass", "PIA", Q_NULLPTR));
        CtlPoints->setText(QApplication::translate("PIAGUIClass", "Control Vertices", Q_NULLPTR));
        CtlPoly->setText(QApplication::translate("PIAGUIClass", "Control Polygon", Q_NULLPTR));
        CurvaturePole->setText(QApplication::translate("PIAGUIClass", "Curvature Pole", Q_NULLPTR));
        BsplineCurve->setText(QApplication::translate("PIAGUIClass", "B-spline Curve", Q_NULLPTR));
        OneStepIterate->setText(QApplication::translate("PIAGUIClass", "One Step Iterate", Q_NULLPTR));
        label->setText(QApplication::translate("PIAGUIClass", "Display Option", Q_NULLPTR));
        LSPIAButton->setText(QApplication::translate("PIAGUIClass", "LSPIA", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("PIAGUIClass", "RadioButton", Q_NULLPTR));
        TargetError->setText(QApplication::translate("PIAGUIClass", "0.01", Q_NULLPTR));
        label_3->setText(QApplication::translate("PIAGUIClass", "Target Error", Q_NULLPTR));
        DataPoints->setText(QApplication::translate("PIAGUIClass", "Data Vertices", Q_NULLPTR));
        label_5->setText(QApplication::translate("PIAGUIClass", "Points On Curve", Q_NULLPTR));
        PosNum->setText(QApplication::translate("PIAGUIClass", "1000", Q_NULLPTR));
        label_6->setText(QApplication::translate("PIAGUIClass", "+1", Q_NULLPTR));
        file->setTitle(QApplication::translate("PIAGUIClass", "File", Q_NULLPTR));
        data->setTitle(QApplication::translate("PIAGUIClass", "Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PIAGUIClass: public Ui_PIAGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIAGUI_H
