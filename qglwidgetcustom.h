#ifndef QGLWIDGETCUSTOM_H
#define QGLWIDGETCUSTOM_H

#include <QGLWidget>
#include <QWidget>
#include "object.h"

class QGLWidgetCustom : public QGLWidget
{
    Q_OBJECT
public:
    explicit QGLWidgetCustom(QWidget *parent = 0);
    void addObject(Object* object);
    void lookAt(int x, int y, int z, int centerX, int centerY, int centerZ, int upX, int upY,int upZ);
    void setCamera(int x, int y, int z, int centerX, int centerY, int centerZ, int upX, int upY,int upZ);
signals:

public slots:

protected:
    QList<Object*> objects;
    //Camera camera;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // QGLWIDGETCUSTOM_H
