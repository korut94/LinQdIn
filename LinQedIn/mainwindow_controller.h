#ifndef MAINWINDOW_CONTROLLER_H
#define MAINWINDOW_CONTROLLER_H

#include "mainwindow_model.h"
#include "mainwindow_view.h"

class MainWindow_Controller
{
    private:
        MainWindow_Model * model;
        MainWindow_View * view;

    public:
        MainWindow_Controller( MainWindow_Model * = new MainWindow_Model,
                               MainWindow_View * = new MainWindow_View );
        ~MainWindow_Controller();
};

#endif // MAINWINDOW_CONTROLLER_H
