#include "admininterface_controller.h"


void AdminInterface_Controller::connetti() const
{
    QObject::connect( view,
                      SIGNAL( requestToSearchUsers() ),
                      this,
                      SLOT( setSearchWindow() ) );

    QObject::connect( this,
                      SIGNAL( display( QWidget * ) ),
                      view,
                      SLOT( setFrameUtility( QWidget * ) ) );
}


void AdminInterface_Controller::setSearchWindow()
{
    emit display( new QPushButton( "Premi" ) );
}


AdminInterface_Controller::AdminInterface_Controller()
{
    model = new AdminInterface_Model();
    view = new AdminInterface_View();

    connetti();
}


AdminInterface_Controller::
AdminInterface_Controller( AdminInterface_Model * m, AdminInterface_View * v )
                           : model( m ), view( v )
{
    connetti();
}


AdminInterface_Controller::~AdminInterface_Controller()
{
    delete model;
    delete view;
}


AdminInterface_View * AdminInterface_Controller::getView() const
{
    return view;
}
