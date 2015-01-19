#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include "admininterface_controller.h"

class AdminInterface
{
    private:
        AdminInterface_Controller * controller;

    public:
        AdminInterface();
        ~AdminInterface();

        QWidget * getView() const;
};

#endif // ADMININTERFACE_H
