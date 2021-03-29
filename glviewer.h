#ifndef GLVIEWER_H
#define GLVIEWER_H

#include <QGLWidget>
#include <QKeyEvent>
#include "quads.h"
#include <QTimer>
class GLViewer : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLViewer(QWidget *parent =0);
    ~GLViewer();



protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
private:
    void draw();
    void drawCube();
    void drawQuads();
    void drawGrid();
    void keyPressEvent(QKeyEvent *event);
    Quads *renderQuads;
    QTimer timer;

};

#endif // GLVIEWER_H
