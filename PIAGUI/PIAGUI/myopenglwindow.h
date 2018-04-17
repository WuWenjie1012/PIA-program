#pragma once


#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
//#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
//#include <QMatrix4x4>
#include <QtGui/QWindow>
#include <QMouseEvent>  
#include <GL/glu.h>

class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
	MyOpenGLWidget(QWidget* parent);
	~MyOpenGLWidget();


private:
	QOpenGLBuffer m_vertex;
	//QOpenGLVertexArrayObject m_vao;
	QOpenGLShaderProgram *m_program;

	GLuint m_posAttr;
	GLuint m_colAttr;
	GLuint m_matrixUniform;
	int m_frame;
	int width_;
	int height_;
	float elevation_ = 0.0;
	float azimuth_ = 0.0;
	float dist_ = 3.0;
	float tanslate_x = 0.0;
	float tanslate_y = 0.0;

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;
	void mouseMoveEvent(QMouseEvent *e);//����ƶ��¼�
	void mousePressEvent(QMouseEvent *e);//��갴���¼�
	void wheelEvent(QWheelEvent*event);//�������¼�
	QPoint m_lastPos;//���������һ����
};