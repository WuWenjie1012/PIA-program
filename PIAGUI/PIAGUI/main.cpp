#include "PIAGUI.h"
#include <QtWidgets/QApplication>

Curve *mCurve = NULL;
Surface *mSurface = NULL;
bool DataPointOpen = true;
bool CtlPointOpen = true;
bool CurvatureOpen = false;
bool CtlPolyOpen = true;
bool BsplineCurveOpen = true;
int Method = 0;	//	0 - PIA, 1 - LSPIA

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PIAGUI w;
	w.show();
	return a.exec();
}
