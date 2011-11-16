#include "qglwidgetcustom.h"

QGLWidgetCustom::QGLWidgetCustom(QWidget *parent) :
    QGLWidget(parent),
    keyTranslationUnit(0.1),
    cameraPosition(Point3(0,0,0)),
    cameraLookTo(Point3(0,4,4)),
    cameraUpVector(Vector3(0,0,1)) {
}

void QGLWidgetCustom::addObject(Object* object) {
    this->objects.append(object);
}

void QGLWidgetCustom::initializeGL() {
    glClearColor(0.0, 0.0, 0.0, 1);
    //qglClearColor(Qt::white);
}

void QGLWidgetCustom::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    // setup project matrix
    glMatrixMode(GL_PROJECTION);
    //Limpa a matriz corrente
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void QGLWidgetCustom::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    camera.lookTo(cameraPosition, cameraLookTo, cameraUpVector);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    for(int i = 0; i < objects.size(); ++i) {
        objects[i]->draw();
    }
}

void QGLWidgetCustom::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
    case Qt::Key_Up:
        this->cameraLookTo.y += keyTranslationUnit;
        break;
    case Qt::Key_Down:
        this->cameraLookTo.y -= keyTranslationUnit;
        break;
    case Qt::Key_Right:
        this->cameraLookTo.x += keyTranslationUnit;
        break;
    case Qt::Key_Left:
        this->cameraLookTo.x -= keyTranslationUnit;
        break;
    case Qt::Key_W:
        this->cameraPosition.z += keyTranslationUnit;
        break;
    case Qt::Key_S:
        this->cameraPosition.z -= keyTranslationUnit;
        break;
    case Qt::Key_D:
        this->cameraPosition.x += keyTranslationUnit;
        this->cameraLookTo.x += keyTranslationUnit;
        break;
    case Qt::Key_A:
        this->cameraPosition.x -= keyTranslationUnit;
        this->cameraLookTo.x -= keyTranslationUnit;
        break;
    }
    updateGL();
}
