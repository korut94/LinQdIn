#include "mainwindow_model.h"

MainWindow_Model::MainWindow_Model()
{
    user = new UserInterface_Controller();
    admin = new AdminInterface_Controller( user );
}


MainWindow_Model::~MainWindow_Model()
{
    delete admin;
    delete user;
}


AdminInterface_Controller * MainWindow_Model::getControllerAdmin() const
{
    return admin;
}


UserInterface_Controller * MainWindow_Model::getControllerUser() const
{
    return user;
}
