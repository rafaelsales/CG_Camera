#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "torusobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TorusObject* torus = new TorusObject();
    ui->widget->addObject(torus);
}

MainWindow::~MainWindow()
{
    delete ui;
}
