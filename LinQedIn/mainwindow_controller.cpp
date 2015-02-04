#include "mainwindow_controller.h"

void MainWindow_Controller::reset( int interface )
{
    switch( interface )
    {
        case 0 : model->getControllerAdmin()->reset();
                 break;
        case 1 : model->getControllerUser()->reset();
                 break;
    }
}


MainWindow_Controller::MainWindow_Controller( MainWindow_Model * m,
                                              MainWindow_View * v )
                                              : model( m ),
                                                view( v )
{
    view->addInterface( model->getControllerAdmin()->getView(),
                        "Administrator" );
    view->addInterface( model->getControllerUser()->getView(), "User" );

    view->show();

    connect( view,
             SIGNAL( currentInterface( int ) ),
             this,
             SLOT( reset( int ) ) );
}


MainWindow_Controller::~MainWindow_Controller()
{
    delete model;
    delete view;
}
