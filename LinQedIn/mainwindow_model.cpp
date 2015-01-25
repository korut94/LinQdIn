#include "mainwindow_model.h"

MainWindow_Model::MainWindow_Model()
                  : admin( new AdminInterface_Controller ),
                    user( new UserInterface_Controller )
{
}


AdminInterface_View * MainWindow_Model::getViewAdmin() const
{
    return admin->getView();
}


UserInterface_View * MainWindow_Model::getViewUser() const
{
    return user->getView();
}
