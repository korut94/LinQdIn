#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindow_controller.h"
#include "mainwindow_model.h"
#include "mainwindow_view.h"

class MainWindow
{
    private:
        MainWindow_Controller * controller;

    public:
        MainWindow();
        ~MainWindow();
};

#endif // MAINWINDOW_H
