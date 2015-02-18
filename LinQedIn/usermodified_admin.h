#ifndef USERMODIFIED_ADMIN_H
#define USERMODIFIED_ADMIN_H

#include "usermodified.h"

class UserModified_Admin : public UserModified
{
    Q_OBJECT

    signals:
        void modify( const Info &, LevelAccess::Type ) const;

    public slots:
        void checkToSanityInsert() const;

    public:
        UserModified_Admin( const smartptr_utente & );
        ~UserModified_Admin();
};

#endif // USERMODIFIED_ADMIN_H
