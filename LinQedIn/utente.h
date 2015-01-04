#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include <QVector>

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
                QVector<smartptr_utente> users;

            public:
                Rete();

                bool isPresent( const Utente & ) const;

                void addUser( Utente & );
                void removeUser( const Utente & );
        };

    private:
        bool online;
        bool activate;

        Info infoUser;

        Rete contacts;

        std::string password; //class Password?
        std::string username;

    public:
        Utente();
        Utente( const std::string &, const std::string &, const Info & );
        virtual ~Utente();

        bool isActivate() const;
        bool isOnline() const;
        bool operator==( const Utente & ) const;
        bool operator!=( const Utente & ) const;

        Info & getInfo();

        std::string getUsername() const;

        void addContact( Utente & );
        void removeContact( const Utente & );

        friend std::ostream & operator<<( std::ostream &, const Utente & );
};

#endif // UTENTE_H
