#ifndef MAINWINDOW_MODEL_H
#define MAINWINDOW_MODEL_H

#include "admininterface_controller.h"
#include "userinterface_controller.h"

class MainWindow_Model
{
    private:
        AdminInterface_Controller * admin;
        UserInterface_Controller * user;

    public:
        MainWindow_Model();
        ~MainWindow_Model();

        AdminInterface_Controller * getControllerAdmin() const;
        UserInterface_Controller * getControllerUser() const;
};

#endif // MAINWINDOW_MODEL_H
