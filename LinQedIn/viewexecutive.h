#ifndef VIEWEXECUTIVE_H
#define VIEWEXECUTIVE_H

#include "viewbusiness.h"

class ViewExecutive : public ViewOther
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
        void viewListFriends( const Utente::Rete & ) const;

    public slots:
        void loadMainPage( const smartptr_utente & user );

    public:
        ViewExecutive( QWidget * = nullptr );
        ~ViewExecutive();
};

#endif // VIEWEXECUTIVE_H
