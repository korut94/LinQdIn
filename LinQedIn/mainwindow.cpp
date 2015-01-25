#include "mainwindow.h"

MainWindow::MainWindow()
{
    controller = new MainWindow_Controller();
}


MainWindow::~MainWindow()
{
    delete controller;
}
