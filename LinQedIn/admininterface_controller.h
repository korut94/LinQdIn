#ifndef ADMININTERFACE_CONTROLLER_H
#define ADMININTERFACE_CONTROLLER_H

#include "admininterface_model.h"
#include "admininterface_view.h"

class AdminInterface_Controller
{
    private:
        AdminInterface_Model * model;
        AdminInterface_View * view;

    public:
        AdminInterface_Controller( AdminInterface_Model *,
                                   AdminInterface_View * );
        ~AdminInterface_Controller();

        AdminInterface_View * getView() const;
};

#endif // ADMININTERFACE_CONTROLLER_H
