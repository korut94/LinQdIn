#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include <QList>

#include "info.h"
#include "entity.h"
#include "smartptr_utente.h"

class smartptr_utente;

class Utente : public Entity
{
    public:
        class Rete
        {
            private:
                QList<smartptr_utente> users;

            public:
                Rete();

                bool isPresent( const smartptr_utente & ) const;

                void addUser( const smartptr_utente &  );
                void removeUser( const smartptr_utente &  );
        };

    private:
        bool online;
        bool activate;

        Rete contacts;

    public:
        Utente();
        Utente( const QString &, const Info & );
        virtual ~Utente();

        bool isActivate() const;
        bool isOnline() const;

        Rete & getContatti();
        const Rete & getContatti() const;

        void addContact( const smartptr_utente & );
        void removeContact( const smartptr_utente & );
        void setActivate( bool );
        void setOnline( bool );

        friend std::ostream & operator<<( std::ostream &, const Utente & );
};

#endif // UTENTE_H
