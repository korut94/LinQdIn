#ifndef USERINTERFACE_CONTROLLER_H
#define USERINTERFACE_CONTROLLER_H

#include <QObject>

#include "userinterface_model.h"
#include "userinterface_view.h"

class UserInterface_Controller : public QObject
{
    Q_OBJECT

    private:
        UserInterface_Model * model;
        UserInterface_View * view;

    public:
        /*
         * Inserita keywork inline per risolvere errore di
         * undefined reference to vtable
         */
        inline UserInterface_Controller();
        inline ~UserInterface_Controller();

        UserInterface_View * getView() const;
};

#endif // USERINTERFACE_CONTROLLER_H
