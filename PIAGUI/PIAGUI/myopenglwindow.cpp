#include "myopenglwindow.h"
#include "Curve.h"

extern Curve *mCurve;
extern bool DataPointOpen;
extern bool CtlPointOpen;
extern bool CtlPolyOpen;
extern bool BsplineCurveOpen;
extern bool CurvatureOpen;

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
	, m_program(0)
	, m_frame(0)
{
	//  The following is not compulsory
	QSurfaceFormat format;
}

MyOpenGLWidget::~MyOpenGLWidget() {

}


void MyOpenGLWidget::initializeGL()
{
	//  Initialize the OpenGL
	initializeOpenGLFunctions();
	glShadeModel(GL_SMOOTH); // Gouraud shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
	if (h == 0) h = 1; // height == 0 not allowed

	glViewport(0, 0, w, h);

	width_ = w;
	height_ = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Calculate The Perspective of the winodw
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//
void MyOpenGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Set lookat point
	glLoadIdentity();
	gluLookAt(0, 0, dist_, 0, 0, 0, 0, 1, 0);

	glRotatef(elevation_, 1, 0, 0);
	glRotatef(azimuth_, 0, 1, 0);
	glTranslatef(tanslate_x, tanslate_y, 0.0);
	if (mCurve)
	{
		if (CtlPointOpen == true && mCurve->GetCtlPoints().rows() != 0)
		{
			Eigen::MatrixXd pt = mCurve->GetCtlPoints();
			glPointSize(4.0f);
			glBegin(GL_POINTS);
			glColor3d(1.0, 0.0, 0.0);
			for (int i = 0; i < mCurve->GetCtlNum() + 1; i++)
			{

				glVertex3d(pt.row(i).x(), pt.row(i).y(), pt.row(i).z());

			}
			glEnd();
		}

		if (DataPointOpen == true && mCurve->GetDataPoints().size() != 0)
		{
			vector<Cpoint> pt = mCurve->GetDataPoints();
			glPointSize(4.0f);
			glBegin(GL_POINTS);
			glColor3d(0.5, 0.5, 0.5);
			for (int i = 0; i < mCurve->GetDataNum() + 1; i++)
			{

				glVertex3d(pt[i].x(), pt[i].y(), pt[i].z());

			}
			glEnd();
		}
		
		if (CtlPolyOpen == true && mCurve->GetCtlPoints().rows() != 0)
		{
			Eigen::MatrixXd pt = mCurve->GetCtlPoints();
			glLineWidth(1.0f);
			glBegin(GL_LINES);
			glColor3d(1.0, 0.0, 0.0);
			for (int i = 0; i < mCurve->GetCtlNum(); i++)
			{

				glVertex3d(pt.row(i).x(), pt.row(i).y(), pt.row(i).z());
				glVertex3d(pt.row(i + 1).x(), pt.row(i + 1).y(), pt.row(i + 1).z());

			}
			glEnd();
		}
		
		if (BsplineCurveOpen == true && mCurve->GetCurvePoints().size() != 0)
		{
			vector<Cpoint> pt = mCurve->GetCurvePoints();
			glLineWidth(1.0f);
			glBegin(GL_LINES);
			glColor3d(0.0, 1.0, 0.0);
			for (int i = 0; i < mCurve->GetPosNum(); i++)
			{
				glVertex3d(pt[i].x(), mCurve->GetCurvePoints()[i].y(), pt[i].z());
				glVertex3d(pt[i + 1].x(), mCurve->GetCurvePoints()[i + 1].y(), pt[i + 1].z());
			}
			glEnd();
		}	

		if (CurvatureOpen == true && mCurve->GetCurvature().size() != 0)
		{
			vector<Cpoint> pt = mCurve->GetCurvePoints();
			vector<Cpoint> ptf = mCurve->GetFirstDerivative();
			vector<double> ptc = mCurve->GetCurvature();
			double scale = 0;
			glLineWidth(1.0f);
			glBegin(GL_LINES);
			glColor3d(0.0, 1.0, 0.0);
			for (int i = 0; i < mCurve->GetPosNum(); i++)
			{
				scale = ptc[i] /(ptf[i].norm() * 200);
				glVertex3d(pt[i].x(), pt[i].y(), pt[i].z());
				glVertex3d(pt[i].x() + ptf[i].y() * scale, pt[i].y() - ptf[i].x() * scale, pt[i].z());
			}
			glEnd();
		}
	}

	update();
}

void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *e)
{
	float dx = e->x() - m_lastPos.x();
	float dy = e->y() - m_lastPos.y();

	if (e->buttons() & Qt::LeftButton)
	{
		azimuth_ += 180 * dx / 1026;
		elevation_ += 180 * dy / 703;
		update();
	}

	if (e->buttons() & Qt::RightButton)
	{
		tanslate_x += dx / 1026;
		tanslate_y -= dy / 703;
		update();
	}

	m_lastPos = e->pos();
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *e)
{
	m_lastPos = e->pos();
}

void MyOpenGLWidget::wheelEvent(QWheelEvent*e)
{
	if (e->delta()>0)
	{
		dist_ -= 0.1;
	}
	else if (e->delta()<0)
	{
		dist_ += 0.1;
	}
	update();

}
