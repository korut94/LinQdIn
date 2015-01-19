#include "admininterface_controller.h"

AdminInterface_Controller::
AdminInterface_Controller( AdminInterface_Model * m, AdminInterface_View * v )
                           : model( m ), view( v )
{
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
