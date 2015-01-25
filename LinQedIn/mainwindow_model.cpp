#include "mainwindow_model.h"

MainWindow_Model::MainWindow_Model()
                  : admin( new AdminInterface_Controller ),
                    user( new UserInterface_Controller )
{
}
