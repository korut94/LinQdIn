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
        void addFriend();
        void logoutUser();
        void manageError( ErrorState::Type );
        void modifyUser( const Info & );
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
