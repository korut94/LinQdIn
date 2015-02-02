#ifndef ADMININTERFACE_CONTROLLER_H
#define ADMININTERFACE_CONTROLLER_H

#include <iostream>
#include <QObject>

#include "admininterface_model.h"
#include "admininterface_view.h"
#include "info.h"
#include "searchgrouputente.h"
#include "userinsert.h"
#include "userinterface_view.h"
#include "usersearch.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"

class AdminInterface_Controller : public QObject
{
    Q_OBJECT

    private:
        AdminInterface_Model * model;
        AdminInterface_View * view;

        smartptr_utente userSelected;

        UserInsert * insert;

        void connetti() const;

	signals:
		void updateListUsers( const QVector<smartptr_utente> & );

    public slots:
        void addUser( const Info & );
        void removeUserSelected();
        void setInsertWindow();
        void setSearchWindow();
        void setUserWindow( const QString & );
        void setUserWindow( const smartptr_utente & );
        void searchUser( const Info & );
        void viewUsers();
        void test( const QString & ) const;

    public:
        AdminInterface_Controller( AdminInterface_Model * =
                                        new AdminInterface_Model,
                                   AdminInterface_View * =
                                        new AdminInterface_View );
        ~AdminInterface_Controller();

        AdminInterface_View * getView() const;
};

#endif // ADMININTERFACE_CONTROLLER_H
