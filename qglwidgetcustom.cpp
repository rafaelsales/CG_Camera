#include "qglwidgetcustom.h"
#include "object.h"
#include "point3.h"
#include "vector3.h"

QGLWidgetCustom::QGLWidgetCustom(QWidget *parent) :
    QGLWidget(parent) {
}

void QGLWidgetCustom::addObject(Object* object) {
    this->objects.append(object);
}

void QGLWidgetCustom::setCamera(int x, int y, int z, int centerX, int centerY, int centerZ, int upX, int upY,int upZ) {
    //this->camera.position = Point3(x, y, z);
    //this->camera.lookTo = Point3(centerX, centerY, centerZ);
    //this->camera.up = Vector3(upX, upY, upZ);
}

void QGLWidgetCustom::initializeGL() {
    glClearColor(0.0, 0.0, 0.0, 1);
    //qglClearColor(Qt::white);
}

void QGLWidgetCustom::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    // setup project matrix
}

void QGLWidgetCustom::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // camera.glDraw();

    for(int i = 0; i < objects.size(); ++i) {
        objects[i]->draw();
    }
}
