#include "userinterface_controller.h"

void UserInterface_Controller::connetti() const
{
    connect( view, SIGNAL( requestModify() ), this, SLOT( loadModifyPage() ) );
}


void UserInterface_Controller::loadModifyPage()
{
    std::cout << "Prova" << std::endl;
}


void UserInterface_Controller::loadUserPage()
{

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
