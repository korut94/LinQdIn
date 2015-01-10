#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include <QList>

#include "info.h"
#include "smartclass.h"
#include "smartptr_utente.h"

class smartptr_utente;

class Utente : public SmartClass
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

        Info infoUser;

        Rete contacts;

        std::string password; //class Password?
        QString username;

    public:
        Utente();
        Utente( const QString &, const std::string &, const Info & );
        virtual ~Utente();

        bool isActivate() const;
        bool isOnline() const;
        bool operator==( const Utente & ) const;
        bool operator!=( const Utente & ) const;

        Info & getInfo();
        const Info & getInfo() const;

        QString getUsername() const;

        void addContact( const smartptr_utente & );
        void removeContact( const smartptr_utente & );

        friend std::ostream & operator<<( std::ostream &, const Utente & );
};

#endif // UTENTE_H
