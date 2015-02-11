#ifndef USERINTERFACE_VIEW_H
#define USERINTERFACE_VIEW_H

#include <iostream>
#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "boardfriends.h"
#include "errorstate.h"
#include "id.h"
#include "info.h"
#include "levelaccess.h"
#include "lineeditvalidate.h"
#include "smartptr_utente.h"
#include "tableusers.h"
#include "top.h"
#include "viewexperience.h"

class UserInterface_View : public QWidget
{
    Q_OBJECT

    private:
        LineEditValidate * editUsername;
        QLabel * errorLogin;

        QScrollArea * userUtility;

    signals:
        void error( ErrorState::Type ) const;
        void requestAddFriend() const;
        void requestHome() const;
        void requestLogin( const QString & ) const;
        void requestLogout() const;
        void requestModify() const;
        void requestRemoveFriend() const;
        void requestSearch() const;
        void requestViewFriend( const QString & ) const;
        void topSetFriend( bool ) const;
        void viewListFriends( const Utente::Rete & ) const;

    public slots:
        void errorLoginMessage( const QString & );
        void loadLoginPage();
        void loadMainPage( const smartptr_utente &, LevelAccess::Type );
        void login();
        void myFriend( bool );
        void setFrameUtility( QWidget * );

    public:
        UserInterface_View( QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
