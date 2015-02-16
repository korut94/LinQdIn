#ifndef VIEWBUSINESS_H
#define VIEWBUSINESS_H

#include "viewbasic.h"

class ViewBusiness : public ViewOther
{    
    Q_OBJECT

    signals:
        void requestAddFriend() const;
        void requestHome() const;
        void requestRemoveFriend() const;

    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewBusiness( QWidget * = nullptr );
        ~ViewBusiness();
};

#endif // VIEWBUSINESS_H
