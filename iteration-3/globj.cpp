//Varun Dalal A04743047
#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"
#include<QWidget>
#include<QMainWindow>

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{
   this->resize(800,600);
}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Resizing the screen and keeping objects intact//
void GLobj::resizeGL( int w, int h )
{

    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized
}

//Paints the GL scene
void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);


//Snippet for drawing a point//
    glBegin(GL_POINTS);
         glPointSize(4.0f);
         glColor3f(1.0f,-1.0f,-1.0f);
         glVertex3f(-0.9,0.8,0.0);
         glColor3f(1.0f,1.0f,-1.0f);
         glVertex3f(-0.85,0.8,0.0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.8,0.8,0.0);
    glEnd();

//Snippet for drawing a line//
    glBegin(GL_LINES);
         glLineWidth(2.0f);
    glColor3f(1.0f,1.0f,0.0f);
    //Horizontal line
         glVertex3f(-0.9,0.6,0.0);
         glVertex3f(-0.7,0.6,0.0);
    //Vertical line
         glVertex3f(-0.6,0.6,0.0);
         glVertex3f(-0.6,0.8,0.0);
    glEnd();

//Snippet for drawing a triangle//
    glBegin(GL_TRIANGLES);
         glColor3f(1.0f,0.5f,0.2f);
         glVertex3f(0.3,0.5,0.0);
         glVertex3f(-0.3,0.5,0.0);
          glVertex3f(0.0,0.8,0.0);
    glEnd(); 

//Snippet for drawing a Quadrilateral//
    glBegin(GL_QUADS);
         glColor3f(0.7f,0.2f,1.0f);
         glVertex3f(0.6,0.5,0.0);
         glVertex3f(0.9,0.5,0.0);
         glVertex3f(0.8,0.8,0.0);
         glVertex3f(0.7,0.8,0.0);
    glEnd();

//Snippet for drawing a Hexagon//
    glBegin(GL_POLYGON);
         glColor3f(0.2f,0.8f,0.8f);
          glVertex3f(0.6,-0.3,0.0);
          glVertex3f(0.4,-0.4,0.0);
          glVertex3f(0.4,-0.6,0.0);
          glVertex3f(0.6,-0.7,0.0);
    glVertex3f(0.8,-0.6,0.0);
          glVertex3f(0.8,-0.4,0.0);
    glEnd();

//Snippet for drawing a cube//
    glBegin(GL_QUADS);
    // Define vertices in counter-clockwise (CCW) order with normal pointing out

    // Top face (y = 1.0f)
         glColor3f(0.0f, 1.0f, 0.0f); // Green
         glVertex3f(-0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, 0.1f, 0.1f);
         glVertex3f(-0.1f, 0.1f, 0.1f);
    // Bottom face (y = -1.0f)
         glColor3f(1.0f, 0.5f, 0.0f); // Orange
         glVertex3f(-0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, 0.1f, 0.1f);
         glVertex3f(-0.1f, 0.1f, 0.1f);
    // Front face (z = 1.0f)
         glColor3f(1.0f, -0.2f, 0.0f); // Red
         glVertex3f(-0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, 0.1f, 0.1f);
         glVertex3f(-0.1f, 0.1f, 0.1f);
    // Back face (z = -1.0f)
         glColor3f(1.0f, 1.0f, 0.0f); // Yellow
         glVertex3f(-0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, 0.1f, 0.1f);
         glVertex3f(-0.1f, 0.1f, 0.1f);
    // Left face (x = -1.0f)
         glColor3f(0.0f, 0.0f, 1.0f); // Blue
         glVertex3f(-0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, 0.1f, 0.1f);
         glVertex3f(-0.1f, 0.1f, 0.1f);
    // Right face (x = 1.0f)
         glColor3f(1.0f, 0.0f, 1.0f); // Magenta
         glVertex3f(-0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, -0.1f, 0.1f);
         glVertex3f( 0.1f, 0.1f, 0.1f);
         glVertex3f(-0.1f, 0.1f, 0.1f);
         glEnd();


    glFlush ();
}



