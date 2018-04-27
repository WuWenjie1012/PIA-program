#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PIAGUI.h"
#include <QFileDialog>
//#include "Mathematic.h"
//#include "Bspline.h"
#include <string>
//#include <Eigen\Core>
#include "Curve.h"


class PIAGUI : public QMainWindow
{
	Q_OBJECT

public:
	PIAGUI(QWidget *parent = Q_NULLPTR);

//	Object mObject;
//	vector<Object> mObject_;	// Object sequence, for back up
	

private slots:
	void loadDataFromFile();	// Load data from file
	void dataGcur();	// The data file g.cur
	void DisplayCtlPoints();	// Display the control points
	void DisplayBsplineCurve();	// Display the B-spline curve
	void DisplayCtlPoly();		// Display the control polygon
	void DisplayDataPoints();	// Display the data points
	void DisplayCurvature();	// Display the Curvature

	void OneStepIterate();		// One step iterate
	void m_PIAButton();			// PIA button
	void m_LSPIAButton();			// LSPIA button

	void SetCtlNum();			// Set the number of control points
private:
	Ui::PIAGUIClass ui;

	enum IterateType
	{
		PIA,
		LSPIA
	}IteType;

	QString FilePathName;
	double PresentError;
	double TargetError;
	//QButtonGroup *
};
