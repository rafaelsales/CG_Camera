#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "torusobject.h"
#include <GL/gl.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TorusObject* torus = new TorusObject();
    ui->glwidget->addObject(torus);
}

MainWindow::~MainWindow()
{
    delete ui;
}
