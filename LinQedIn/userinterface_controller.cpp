#include "userinterface_controller.h"

void UserInterface_Controller::connetti() const
{
    connect( view, SIGNAL( requestModify() ), this, SLOT( setUserModify() ) );
    connect( this,
             SIGNAL( display( QWidget * ) ),
             view,
             SLOT( setFrameUtility( QWidget * ) ) );
}


void UserInterface_Controller::setUserModify()
{
    UserModified * search = new UserModified();

    emit display( search );
}


UserInterface_Controller::UserInterface_Controller()
                          : view( new UserInterface_View ),
                            model( new UserInterface_Model )
{
    connetti();
}


UserInterface_Controller::~UserInterface_Controller()
{
    delete view;
    delete model;
}


UserInterface_View * UserInterface_Controller::getView() const
{
    return view;
}
