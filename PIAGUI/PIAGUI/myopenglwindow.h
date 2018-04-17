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
	void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件
	void mousePressEvent(QMouseEvent *e);//鼠标按下事件
	void wheelEvent(QWheelEvent*event);//鼠标滚轮事件
	QPoint m_lastPos;//鼠标点击的上一个点
};