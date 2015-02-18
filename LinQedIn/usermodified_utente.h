#ifndef USERMODIFIED_UTENTE_H
#define USERMODIFIED_UTENTE_H

#include "usermodified.h"

class UserModified_Utente : public UserModified
{
    Q_OBJECT

    signals:
        void modify( const Info & ) const;

    public slots:
        void checkToSanityInsert() const;

    public:
        UserModified_Utente( const smartptr_utente & );
        ~UserModified_Utente();
};

#endif // USERMODIFIED_UTENTE_H
