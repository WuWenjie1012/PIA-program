#include "PIAGUI.h"
#include <QtWidgets/QApplication>

Curve *mCurve = NULL;
Surface *mSurface = NULL;
bool DataPointOpen = true;
bool CtlPointOpen = true;
bool CurvatureOpen = false;
bool CtlPolyOpen = true;
bool BsplineCurveOpen = true;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PIAGUI w;
	w.show();
	return a.exec();
}
