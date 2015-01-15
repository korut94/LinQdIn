#include "mainwindow_controller.h"

MainWindow_Controller::MainWindow_Controller( MainWindow_Model * m,
                                              MainWindow_View * v )
                                              : model( m ),
                                                view( v )
{
    view->show();
}


MainWindow_Controller::~MainWindow_Controller()
{
    delete model;
    delete view;
}
