#include "qglwidgetcustom.h"
#include "matrix4.h"

QGLWidgetCustom::QGLWidgetCustom(QWidget *parent) :
    QGLWidget(parent),
    keyTranslationUnit(0.1),
    rotationFactor(1.0 / 60),
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

void QGLWidgetCustom::mouseMoveEvent(QMouseEvent *e) {
    if (mouseLastPosition.x() == 0 && mouseLastPosition.y() == 0) {
        mouseLastPosition = e->pos();
        return;
    }
    int dx = e->x() - mouseLastPosition.x();
    int dy = e->y() - mouseLastPosition.y();
    mouseLastPosition = e->pos();
    this->cameraLookTo = Matrix4::rotationMatrix(dx * rotationFactor, Vector3(0, 1, 0)) * this->cameraLookTo;
    this->cameraLookTo = Matrix4::rotationMatrix(dy * rotationFactor, Vector3(1, 0, 0)) * this->cameraLookTo;
    updateGL();
}

void QGLWidgetCustom::keyPressEvent(QKeyEvent *e) {
    switch(e->key()) {
    case Qt::Key_Up:
        this->cameraLookTo = Matrix4::rotationMatrix(rotationFactor, Vector3(1, 0, 0)) * this->cameraLookTo;
        break;
    case Qt::Key_Down:
        this->cameraLookTo = Matrix4::rotationMatrix(-rotationFactor, Vector3(1, 0, 0)) * this->cameraLookTo;
        break;
    case Qt::Key_Right:
        this->cameraLookTo = Matrix4::rotationMatrix(rotationFactor, Vector3(0, 1, 0)) * this->cameraLookTo;
        break;
    case Qt::Key_Left:
        this->cameraLookTo = Matrix4::rotationMatrix(-rotationFactor, Vector3(0, 1, 0)) * this->cameraLookTo;
        break;
    case Qt::Key_W:
        this->cameraPosition = Matrix4::translationMatrix(Vector3(0, 0, keyTranslationUnit)) * this->cameraPosition;
        break;
    case Qt::Key_S:
        this->cameraPosition = Matrix4::translationMatrix(Vector3(0, 0, -keyTranslationUnit)) * this->cameraPosition;
        break;
    case Qt::Key_D:
        this->cameraPosition = Matrix4::translationMatrix(Vector3(keyTranslationUnit, 0, 0)) * this->cameraPosition;
        this->cameraLookTo = Matrix4::translationMatrix(Vector3(keyTranslationUnit, 0, 0)) * this->cameraLookTo;
        break;
    case Qt::Key_A:
        this->cameraPosition = Matrix4::translationMatrix(Vector3(-keyTranslationUnit, 0, 0)) * this->cameraPosition;
        this->cameraLookTo = Matrix4::translationMatrix(Vector3(-keyTranslationUnit, 0, 0)) * this->cameraLookTo;
        break;
    }
    updateGL();
}
