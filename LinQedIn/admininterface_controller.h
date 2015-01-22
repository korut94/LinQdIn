#ifndef ADMININTERFACE_CONTROLLER_H
#define ADMININTERFACE_CONTROLLER_H

#include <iostream>
#include <QObject>

#include "admininterface_model.h"
#include "admininterface_view.h"

class AdminInterface_Controller : public QObject
{
    Q_OBJECT

    private:
        AdminInterface_Model * model;
        AdminInterface_View * view;

        void connetti() const;

    signals:
        void display( QWidget * );

    public slots:
        void setSearchWindow();

    public:
        AdminInterface_Controller();
        AdminInterface_Controller( AdminInterface_Model *,
                                   AdminInterface_View * );
        ~AdminInterface_Controller();

        AdminInterface_View * getView() const;
};

#endif // ADMININTERFACE_CONTROLLER_H
