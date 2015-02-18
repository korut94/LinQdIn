#ifndef ADMININTERFACE_CONTROLLER_H
#define ADMININTERFACE_CONTROLLER_H

#include <algorithm>
#include <iostream>
#include <QFile>
#include <QObject>
#include <QMessageBox>
#include <QXmlStreamWriter>

#include "admininterface_model.h"
#include "admininterface_view.h"
#include "info.h"
#include "searchgrouputente.h"
#include "userinsert.h"
#include "userinterface_controller.h"
#include "usermodified_admin.h"
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

        smartptr_utente createUser( const QString &,
                                    const Info &,
                                    LevelAccess::Type ) const;
        smartptr_utente createUser( const smartptr_utente &,
                                    LevelAccess::Type );

        void connetti() const;

	signals:
		void updateListUsers( const QVector<smartptr_utente> & );

    public slots:
        void addUser( const Info &, LevelAccess::Type );
        void loadDB();
        void modifyUser( const Info &, LevelAccess::Type );
        void removeUserSelected();
        void reset();
        void saveDB();
        void setInsertWindow();
        void setModifyWindow();
        void setSearchWindow();
        void setUserWindow( const QString & );
        void setUserWindow( const smartptr_utente & );
        void viewUsers();
        void test( const QString & ) const;

    public:
        AdminInterface_Controller( UserInterface_Controller *,
                                   AdminInterface_Model * =
                                        new AdminInterface_Model,
                                   AdminInterface_View * =
                                        new AdminInterface_View );
        ~AdminInterface_Controller();

        AdminInterface_View * getView() const;

        bool modified() const;
};

#endif // ADMININTERFACE_CONTROLLER_H
