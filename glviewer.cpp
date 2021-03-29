#include "glviewer.h"
#include "objectorientation.h"
#include <QtWidgets>
#include <QtOpenGL>
#include <QtOpenGL/QGLWidget>
#include <QDebug>

GLViewer::GLViewer(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers),parent)
{
        grabKeyboard();
        Transform.set_xRot(0);
        Transform.set_yRot(0);
        Transform.set_zRot(0);

        Transform.set_xTran(9);
        Transform.set_yTran(0);
        Transform.set_zTran(9);
        renderQuads = new Quads();

}

GLViewer::~GLViewer()
{
}

void GLViewer::initializeGL()
{
    qglClearColor(Qt::black);

       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       glMatrixMode(GL_MODELVIEW);
       glEnable(GL_DEPTH_TEST);
       glClearColor(0.1,0.1,0.1,1);

}

void GLViewer::paintGL()
{

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(-13, 3, -25.0);
        glRotatef(40, 1.0, 1.0, 0.0);
        //glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
        //glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

        drawGrid();
        drawQuads();
        draw();
}

void GLViewer::resizeGL(int width, int height)
{
        int side = qMin(width, height);
        glViewport((width - side) / 2, (height - side) / 2, side, side);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        //glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
        glFrustum(-1, 1, -1, 1, 1.5, 1000);

        glMatrixMode(GL_MODELVIEW);
}

void GLViewer::draw()
{

       glPushMatrix();

       glRotatef(Transform.get_xRot(), 1.0, 0.0, 0.0);
       glRotatef(Transform.get_yRot(), 0.0, 1.0, 0.0);
       glRotatef(Transform.get_zRot(), 0.0, 0.0, 1.0);

       glTranslatef(Transform.get_xTran(), Transform.get_yTran(), Transform.get_zTran());

        //drawQuads();
       drawCube();
       glPopMatrix();
}

void GLViewer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){Transform.set_zTran(Transform.get_zTran()-1);qDebug() << "Z= "<<Transform.get_zTran(); updateGL();}
    if(event->key() == Qt::Key_S){Transform.set_zTran(Transform.get_zTran()+1);qDebug() << "Z= "<<Transform.get_zTran(); updateGL();}


    if(event->key() == Qt::Key_A){Transform.set_xTran(Transform.get_xTran()-1);qDebug() << "X= "<<Transform.get_xTran(); updateGL();}
    if(event->key() == Qt::Key_D){Transform.set_xTran(Transform.get_xTran()+1);qDebug() << "X= "<<Transform.get_xTran(); updateGL();}

    if(event->key() == Qt::Key_Q){Transform.set_yTran(Transform.get_yTran()+1);qDebug() << "Y= "<<Transform.get_yTran(); updateGL();}
    if(event->key() == Qt::Key_Z){Transform.set_yTran(Transform.get_yTran()-1);qDebug() << "Y= "<<Transform.get_yTran(); updateGL();}

    if(event->key() == Qt::Key_X)
    {
        Transform.set_xTran(9);
        Transform.set_yTran(0);
        Transform.set_zTran(9);
        updateGL();
    }

    if(event->key() == Qt::Key_Space){renderQuads->addQuad(Transform);updateGL();}
    if(event->key() == Qt::Key_R){renderQuads->colorVector[renderQuads->total][0] = 1; renderQuads->colorVector[renderQuads->total][1] = 0; renderQuads->colorVector[renderQuads->total][2] = 0;}
    if(event->key() == Qt::Key_G){renderQuads->colorVector[renderQuads->total][0] = 0; renderQuads->colorVector[renderQuads->total][1] = 1; renderQuads->colorVector[renderQuads->total][2] = 0;}
    if(event->key() == Qt::Key_B){renderQuads->colorVector[renderQuads->total][0] = 0; renderQuads->colorVector[renderQuads->total][1] = 0; renderQuads->colorVector[renderQuads->total][2] = 1;}
}

void GLViewer::drawQuads()
{
 if(renderQuads->total!=-1)
 {
    for(int i = 0; i<renderQuads->total+1; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(renderQuads->colorVector[i][0],renderQuads->colorVector[i][1],renderQuads->colorVector[i][2]);
        //renderQuads->colorVector[i][]
        glVertex3f(renderQuads->quadVector[i][0],renderQuads->quadVector[i][1],renderQuads->quadVector[i][2]);
       // glColor3f(0,1,0);
        glVertex3f(renderQuads->quadVector[i][3],renderQuads->quadVector[i][4],renderQuads->quadVector[i][5]);
        //glColor3f(0,0,1);
        glVertex3f(renderQuads->quadVector[i][6],renderQuads->quadVector[i][7],renderQuads->quadVector[i][8]);
       // glColor3f(1,1,1);
        glVertex3f(renderQuads->quadVector[i][9],renderQuads->quadVector[i][10],renderQuads->quadVector[i][11]);
        glEnd();

    }
}
}

void GLViewer::drawGrid()
{
    for(int i = 0; i<38; i++)
    {
        glPushMatrix();
        if(i<19){glTranslatef(0,0,i);}
        if(i>=19){glTranslatef(i-19,0,0); glRotatef(-90,0,1,0);}

        glBegin(GL_LINES);
        glColor3f(1,1,1); glLineWidth(1);
        glVertex3f(0,-0.1,0); glVertex3f(18,-0.1,0);
        glEnd();
        glPopMatrix();

    }
}

void GLViewer::drawCube()
{

   glScalef(0.4,0.4,0.4);
   glBegin(GL_POLYGON);
           glColor3f(1.0,0.0,1.0);
           glVertex3f(-1.0,1.0,1.0);
           glVertex3f(-1.0,-1.0,1.0);
           glVertex3f(1.0,-1.0,1.0);
           glVertex3f(1.0,1.0,1.0);
           glEnd();
           //back
           glBegin(GL_POLYGON);
           glColor3f(0.0,1.0,0.0);
           glVertex3f(1.0,1.0,-1.0);
           glVertex3f(1.0,-1.0,-1.0);
           glVertex3f(-1.0,-1.0,-1.0);
           glVertex3f(-1.0,1.0,-1.0);
           glEnd();
           //right
           glBegin(GL_POLYGON);
           glColor3f(0.0,0.0,1.0);
           glVertex3f(1.0,1.0,1.0);
           glVertex3f(1.0,-1.0,1.0);
           glVertex3f(1.0,-1.0,-1.0);
           glVertex3f(1.0,1.0,-1.0);
           glEnd();
           //left
           glBegin(GL_POLYGON);
           glColor3f(1.0,1.0,0.0);
           glVertex3f(-1.0,1.0,-1.0);
           glVertex3f(-1.0,-1.0,-1.0);
           glVertex3f(-1.0,-1.0,1.0);
           glVertex3f(-1.0,1.0,1.0);
           glEnd();
           //top
           glBegin(GL_POLYGON);
           glColor3f(0.0,1.0,1.0);
           glVertex3f(-1.0,1.0,-1.0);
           glVertex3f(-1.0,1.0,1.0);
           glVertex3f(1.0,1.0,1.0);
           glVertex3f(1.0,1.0,-1.0);
           glEnd();
           //bottom
           glBegin(GL_POLYGON);
           glColor3f(1.0,0.0,1.0);
           glVertex3f(-1.0,-1.0,-1.0);
           glVertex3f(-1.0,-1.0,1.0);
           glVertex3f(1.0,-1.0,1.0);
           glVertex3f(1.0,-1.0,-1.0);
           glEnd();


}

