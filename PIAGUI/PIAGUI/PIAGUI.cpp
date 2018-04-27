#include "PIAGUI.h"

extern Curve *mCurve;
extern bool CtlPointOpen;
extern bool DataPointOpen;
extern bool CtlPolyOpen;
extern bool BsplineCurveOpen;
extern bool CurvatureOpen;
extern int Method;

PIAGUI::PIAGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(1026, 703);
	//TargetError = ui.TargetError->text().toDouble();
	//cout << TargetError << endl;
	connect(ui.OpenFile, SIGNAL(triggered()), this, SLOT(loadDataFromFile()));	// Load data
	connect(ui.actiongcur, SIGNAL(triggered()), this, SLOT(dataGcur()));	// Load data
	connect(ui.CtlPoints, SIGNAL(clicked()), this, SLOT(DisplayCtlPoints()));	// Display option
	connect(ui.DataPoints, SIGNAL(clicked()), this, SLOT(DisplayDataPoints()));	// Display option
	connect(ui.CtlPoly, SIGNAL(clicked()), this, SLOT(DisplayCtlPoly()));	// Display option
	connect(ui.CurvaturePole, SIGNAL(clicked()), this, SLOT(DisplayCurvature()));	// Display option
	connect(ui.BsplineCurve, SIGNAL(clicked()), this, SLOT(DisplayBsplineCurve()));	// Display option

	connect(ui.OneStepIterate, SIGNAL(clicked()), this, SLOT(OneStepIterate()));	// 
	connect(ui.PIAButton, SIGNAL(clicked()), this, SLOT(m_PIAButton()));	// 
	connect(ui.LSPIAButton, SIGNAL(clicked()), this, SLOT(m_LSPIAButton()));	//

	connect(ui.SetCtlNum, SIGNAL(clicked()), this, SLOT(SetCtlNum()));	// 

	/*if (ui.CtlPoints->checkState() == Qt::Checked)
		CtlPointOpen = true;
	else
		CtlPointOpen = false;*/
}

void PIAGUI::loadDataFromFile()
{
	
	FilePathName = QFileDialog::getOpenFileName(this, QStringLiteral("´ò¿ª"),
		"./Data",
		QStringLiteral("dat file(*.dat);;txt file(*.txt);;cur file(*.cur)"));
	if (FilePathName != NULL)
	{
		
		mCurve = NULL;
		mCurve = new Curve;
		mCurve->SetPosNum(ui.PosNum->text().toInt());
		mCurve->loadDataFromFile(FilePathName);
		ui.DataNum->setText(QString::number(mCurve->GetDataNum() + 1));
		
		switch (IteType)
		{
		case PIAGUI::PIA:
			mCurve->SetIteType(PIA);
			mCurve->Init();
			ui.CtlNum->setText(QString::number(mCurve->GetCtlNum() + 1));
			ui.FittingError->setText(QString::number(mCurve->GetPresentError()));
			break;
		case PIAGUI::LSPIA:
			mCurve->SetIteType(LSPIA);		
			break;
		default:
			break;
		}
		
	}	
}	

void PIAGUI::dataGcur()
{
	FilePathName = "./Data/CurvePoints/g.cur";
	mCurve = NULL;
	mCurve = new Curve;
	mCurve->loadDataFromFile(FilePathName);
	ui.FittingError->setText(QString::number(mCurve->GetPresentError()));
}

void PIAGUI::DisplayCtlPoints()
{
	if (ui.CtlPoints->checkState() == Qt::Checked)
		CtlPointOpen = true;
	else
		CtlPointOpen = false;
}

void PIAGUI::DisplayCtlPoly()
{
	if (ui.CtlPoly->checkState() == Qt::Checked)
		CtlPolyOpen = true;
	else
		CtlPolyOpen = false;
}

void PIAGUI::DisplayBsplineCurve()
{
	if (ui.BsplineCurve->checkState() == Qt::Checked)
		BsplineCurveOpen = true;
	else
		BsplineCurveOpen = false;
}

void PIAGUI::DisplayDataPoints()
{
	if (ui.DataPoints->checkState() == Qt::Checked)
		DataPointOpen = true;
	else
		DataPointOpen = false;
}

void PIAGUI::DisplayCurvature()
{
	if (ui.CurvaturePole->checkState() == Qt::Checked)
		CurvatureOpen = true;
	else
		CurvatureOpen = false;
}

void PIAGUI::OneStepIterate()
{
	switch (IteType)
	{
	case PIAGUI::PIA:
		TargetError = ui.TargetError->text().toDouble();	
		mCurve->OnePIAIterateStep();
		ui.FittingError->setText(QString::number(mCurve->GetPresentError()));
		break;
	case PIAGUI::LSPIA:
		break;
	default:
		break;
	}
}

void PIAGUI::m_PIAButton()
{
	IteType = PIA;
}


void PIAGUI::m_LSPIAButton()
{
	IteType = LSPIA;
}

void PIAGUI::SetCtlNum()
{
	mCurve->SetCtlNum(ui.CtlNum->text().toInt() - 1);
	mCurve->Init();
	ui.CtlNum->setText(QString::number(mCurve->GetCtlNum() + 1));
	ui.FittingError->setText(QString::number(mCurve->GetPresentError()));
}