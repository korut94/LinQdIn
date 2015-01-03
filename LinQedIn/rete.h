#ifndef RETE_H
#define RETE_H

#include <QVector>

#include "utente.h"

class Utente;
class smartptr_utente;

class Rete
{
    private:
        QVector<smartptr_utente> users;

    public:
        Rete();

        bool isPresent( const Utente & ) const;

        void addUser( Utente & );
        void removeUser( const Utente & );
};

#endif // RETE_H
