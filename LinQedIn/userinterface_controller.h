#ifndef USERINTERFACE_CONTROLLER_H
#define USERINTERFACE_CONTROLLER_H

#include <QObject>

#include "usermodified.h"
#include "usersearch.h"
#include "userinterface_model.h"
#include "userinterface_view.h"
#include "viewbasic.h"
#include "viewbusiness.h"
#include "viewexecutive.h"
#include "viewi.h"
#include "myview.h"

class UserInterface_Controller : public QObject
{
    Q_OBJECT

    private:
        UserInterface_Model * model;
        UserInterface_View * view;

        void connetti( ViewBase * ) const;

    signals:
        void updateListFriends( const Utente::Rete & ) const;

    public slots:
        void addFriend();
        void logoutUser();
        void manageError( ErrorState::Type );
        void modifyUser( const Info & );
        void removeFriend();
        void reset();
        void returnHome();
        void searchUser( const QVector<smartptr_utente> & );
        void setUserModify();
        void setUserPage( const QString & );
        void setUserPage( const smartptr_utente & );
        void setUserSearch();

    public:
        UserInterface_Controller();
        ~UserInterface_Controller();

        UserInterface_View * getView() const;

        void linkDatatabase( Database * );
};

#endif // USERINTERFACE_CONTROLLER_H
