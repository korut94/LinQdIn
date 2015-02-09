#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include <QList>

#include "info.h"
#include "entity.h"
#include "levelaccess.h"
#include "smartptr_utente.h"

class smartptr_utente;

class Utente : public Entity
{
    public:
        class Rete : private QList<smartptr_utente>
        {
            public:
                Rete();

                bool isPresent( const smartptr_utente & t ) const;

                QVector<smartptr_utente> toVector() const;

                void add( const smartptr_utente & t );
                void remove( const smartptr_utente & t );
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

		virtual LevelAccess::Type typeAccount() const = 0;

        const Rete & getContatti() const;

        void addContact( const smartptr_utente & );
        void removeContact( const smartptr_utente & );
        void setActivate( bool );
        void setOnline( bool );
};

#endif // UTENTE_H
