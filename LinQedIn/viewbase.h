#ifndef VIEWBASE_H
#define VIEWBASE_H

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

class ViewBase : public QWidget
{
    Q_OBJECT

    signals:
        void requestAddFriend() const;
        void requestHome() const;
        void requestLogout() const;
        void requestModify() const;
        void requestRemoveFriend() const;
        void requestSearch() const;
        void requestViewFriend( const QString & ) const;
        void topSetFriend( bool ) const;
        void viewListFriends( const Utente::Rete & ) const;

    public slots:
        virtual void loadMainPage( const smartptr_utente & ) = 0;
        void myFriend( bool );

    public:
        ViewBase( QWidget * = nullptr );
        ~ViewBase();
};

#endif // VIEWBASE_H
