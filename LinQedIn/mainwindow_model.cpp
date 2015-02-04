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


AdminInterface_View * MainWindow_Model::getViewAdmin() const
{
    return admin->getView();
}


UserInterface_View * MainWindow_Model::getViewUser() const
{
    return user->getView();
}
