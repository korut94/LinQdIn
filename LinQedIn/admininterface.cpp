#include "admininterface.h"

AdminInterface::AdminInterface()
{
    controller = new AdminInterface_Controller( new AdminInterface_Model(),
                                                new AdminInterface_View() );
}


AdminInterface::~AdminInterface()
{
    delete controller;
}


QWidget * AdminInterface::getView() const
{
    return controller->getView();
}
