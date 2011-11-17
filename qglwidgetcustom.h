#ifndef QGLWIDGETCUSTOM_H
#define QGLWIDGETCUSTOM_H

#include <QGLWidget>
#include <QWidget>
#include <QtEvents>
#include "camera.h"
#include "object.h"
#include "point3.h"
#include "vector3.h"

class QGLWidgetCustom : public QGLWidget
{
    Q_OBJECT
public:
    float keyTranslationUnit;
    float rotationFactor;
    QPoint mouseLastPosition;
    Camera camera;
    explicit QGLWidgetCustom(QWidget *parent = 0);
    void addObject(Object* object);
signals:

public slots:

protected:
    QList<Object*> objects;
    Point3 cameraPosition;
    Point3 cameraLookTo;
    Vector3 cameraUpVector;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
};
#endif // QGLWIDGETCUSTOM_H
