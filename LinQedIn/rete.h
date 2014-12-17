#ifndef RETE_H
#define RETE_H

#include <QVector>

#include "smartclass.h"
#include "utente.h"

class Rete : public SmartClass
{
    private:
        QVector<sptr_utente> users;

    public:
        Rete();

        bool isPresent( const Utente & ) const;

        void addUser( const Utente & );
        void removeUser( const Utente & );

        class smartptr_rete : public SmartClass::smartptr
        {
            public:
                smartptr_rete( Rete * = NULL );

                Rete & operator*() const;
                Rete * operator->() const;
        };
};

typedef Rete::smartptr_rete sptr_rete;

#endif // RETE_H
