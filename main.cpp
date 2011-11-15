#include <QtGui/QApplication>
#include <GL/glut.h>
#include "mainwindow.h"
#include "matrix4.h"

int main(int argc, char *argv[])
{
    Matrix4 m;

    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
