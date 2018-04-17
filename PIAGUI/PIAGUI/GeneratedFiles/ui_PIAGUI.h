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
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *FittingError;
    QCheckBox *DataPoints;
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
        PIAButton = new QRadioButton(centralWidget);
        PIAButton->setObjectName(QStringLiteral("PIAButton"));
        PIAButton->setGeometry(QRect(690, 260, 121, 16));
        QFont font;
        font.setPointSize(10);
        PIAButton->setFont(font);
        CtlPoints = new QCheckBox(centralWidget);
        CtlPoints->setObjectName(QStringLiteral("CtlPoints"));
        CtlPoints->setGeometry(QRect(690, 50, 141, 16));
        CtlPoints->setFont(font);
        CtlPoints->setChecked(true);
        CtlPoly = new QCheckBox(centralWidget);
        CtlPoly->setObjectName(QStringLiteral("CtlPoly"));
        CtlPoly->setGeometry(QRect(860, 50, 131, 16));
        CtlPoly->setFont(font);
        CtlPoly->setChecked(true);
        CurvaturePole = new QCheckBox(centralWidget);
        CurvaturePole->setObjectName(QStringLiteral("CurvaturePole"));
        CurvaturePole->setGeometry(QRect(690, 110, 131, 16));
        CurvaturePole->setFont(font);
        CurvaturePole->setChecked(false);
        BsplineCurve = new QCheckBox(centralWidget);
        BsplineCurve->setObjectName(QStringLiteral("BsplineCurve"));
        BsplineCurve->setGeometry(QRect(860, 80, 121, 16));
        BsplineCurve->setFont(font);
        BsplineCurve->setChecked(true);
        OneStepIterate = new QPushButton(centralWidget);
        OneStepIterate->setObjectName(QStringLiteral("OneStepIterate"));
        OneStepIterate->setGeometry(QRect(680, 520, 201, 23));
        OneStepIterate->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 10, 121, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        LSPIAButton = new QRadioButton(centralWidget);
        LSPIAButton->setObjectName(QStringLiteral("LSPIAButton"));
        LSPIAButton->setGeometry(QRect(690, 300, 89, 16));
        LSPIAButton->setFont(font);
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(690, 470, 89, 16));
        radioButton_3->setFont(font);
        TargetError = new QLineEdit(centralWidget);
        TargetError->setObjectName(QStringLiteral("TargetError"));
        TargetError->setEnabled(true);
        TargetError->setGeometry(QRect(830, 160, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(690, 200, 121, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(690, 160, 121, 16));
        label_3->setFont(font1);
        FittingError = new QLineEdit(centralWidget);
        FittingError->setObjectName(QStringLiteral("FittingError"));
        FittingError->setEnabled(false);
        FittingError->setGeometry(QRect(830, 200, 113, 20));
        DataPoints = new QCheckBox(centralWidget);
        DataPoints->setObjectName(QStringLiteral("DataPoints"));
        DataPoints->setGeometry(QRect(690, 80, 141, 16));
        DataPoints->setFont(font);
        DataPoints->setChecked(true);
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
        label_2->setText(QApplication::translate("PIAGUIClass", "Fitting Error", Q_NULLPTR));
        label_3->setText(QApplication::translate("PIAGUIClass", "Target Error", Q_NULLPTR));
        FittingError->setText(QApplication::translate("PIAGUIClass", "9999999", Q_NULLPTR));
        DataPoints->setText(QApplication::translate("PIAGUIClass", "Data Vertices", Q_NULLPTR));
        file->setTitle(QApplication::translate("PIAGUIClass", "File", Q_NULLPTR));
        data->setTitle(QApplication::translate("PIAGUIClass", "Data", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PIAGUIClass: public Ui_PIAGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIAGUI_H
