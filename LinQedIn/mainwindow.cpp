#include "mainwindow.h"

MainWindow::MainWindow()
{
    controller = new MainWindow_Controller( new MainWindow_Model(),
                                            new MainWindow_View() );
}


MainWindow::~MainWindow()
{
    delete controller;
}
