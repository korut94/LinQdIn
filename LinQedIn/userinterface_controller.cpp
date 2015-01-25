#include "userinterface_controller.h"

UserInterface_Controller::UserInterface_Controller()
                          : view( new UserInterface_View ),
                            model( new UserInterface_Model )
{

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
