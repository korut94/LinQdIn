#ifndef USERINTERFACE_CONTROLLER_H
#define USERINTERFACE_CONTROLLER_H

#include <QObject>

#include "usermodified.h"
#include "usersearch.h"
#include "userinterface_model.h"
#include "userinterface_view.h"

class UserInterface_Controller : public QObject
{
    Q_OBJECT

    private:
        UserInterface_Model * model;
        UserInterface_View * view;

        void connetti() const;

    signals:
        void display( QWidget * );

    public slots:
        void setUserModify();

    public:
        UserInterface_Controller();
        ~UserInterface_Controller();

        UserInterface_View * getView() const;
};

#endif // USERINTERFACE_CONTROLLER_H
