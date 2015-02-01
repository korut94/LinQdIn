#include "mainwindow_controller.h"

MainWindow_Controller::MainWindow_Controller( MainWindow_Model * m,
                                              MainWindow_View * v )
                                              : model( m ),
                                                view( v )
{
    view->addInterface( model->getViewAdmin(), "Administrator" );
    view->addInterface( model->getViewUser(), "User" );

    view->show();
}


MainWindow_Controller::~MainWindow_Controller()
{
    delete view;
    delete model;
}
