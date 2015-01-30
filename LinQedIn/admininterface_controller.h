#ifndef ADMININTERFACE_CONTROLLER_H
#define ADMININTERFACE_CONTROLLER_H

#include <iostream>
#include <QObject>

#include "admininterface_model.h"
#include "admininterface_view.h"
#include "info.h"
#include "userinsert.h"
#include "userinterface_view.h"
#include "usersearch.h"

class AdminInterface_Controller : public QObject
{
    Q_OBJECT

    private:
        AdminInterface_Model * model;
        AdminInterface_View * view;

        UserInsert * insert;

        void connetti() const;

    signals:
        void display( QWidget * );

    public slots:
        void catchError();
        void setInsertWindow();
        void setSearchWindow();
        void test( const Info & ) const;

    public:
        AdminInterface_Controller( AdminInterface_Model * =
                                        new AdminInterface_Model,
                                   AdminInterface_View * =
                                        new AdminInterface_View );
        ~AdminInterface_Controller();

        AdminInterface_View * getView() const;
};

#endif // ADMININTERFACE_CONTROLLER_H
