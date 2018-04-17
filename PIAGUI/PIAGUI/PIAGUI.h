#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PIAGUI.h"
#include <QFileDialog>
#include "Mathematic.h"
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
	enum IterateType
	{
		PIA,
		LSPIA
	}IteType;

private slots:
	void loadDataFromFile();	// Load data from file
	void dataGcur();	// The data file g.cur
	void DisplayCtlPoints();	// Display the control points
	void DisplayBsplineCurve();	// Display the B-spline curve
	void DisplayCtlPoly();		// Display the control polygon
	void DisplayDataPoints();	// Display the data points
	void OneStepIterate();		

private:
	Ui::PIAGUIClass ui;

	QString FilePathName;
	double PresentError;
	double TargetError;
};
