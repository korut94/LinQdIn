#include "mainwindow_controller.h"

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
    connect( view,
             SIGNAL( requestClose( QCloseEvent * ) ),
             this,
             SLOT( close( QCloseEvent * ) ) );
}


MainWindow_Controller::~MainWindow_Controller()
{
    delete model;
    delete view;
}


void MainWindow_Controller::close( QCloseEvent * event )
{
    AdminInterface_Controller * adminControl = model->getControllerAdmin();

    if( adminControl->modified() )
    {
        QMessageBox msgBox;

        msgBox.setText(
                    tr( "The database has not saved your modiications" ) );
        msgBox.setStandardButtons( QMessageBox::Save |
                                   QMessageBox::Discard |
                                   QMessageBox::Cancel );

        int ret = msgBox.exec();

        switch( ret )
        {
            case QMessageBox::Save: adminControl->saveDB();
                                    event->accept();
                                    break;

            case QMessageBox::Discard: event->accept();
                                       break;

            case QMessageBox::Cancel: event->ignore();
                                      break;

            default: break;
        }
    }

    else view->close();
}


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
