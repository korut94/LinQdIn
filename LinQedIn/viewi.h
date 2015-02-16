#ifndef VIEWI_H
#define VIEWI_H

#include "viewbase.h"

class ViewI : public ViewBase
{
    Q_OBJECT

    signals:
        void requestHome() const;
        void requestLogout() const;
        void requestModify() const;
        void requestSearch() const;
        void requestViewFriend( const QString & ) const;
        void viewListFriends( const Utente::Rete & ) const;

    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewI( QWidget * = nullptr );
};

#endif // VIEWI_H
