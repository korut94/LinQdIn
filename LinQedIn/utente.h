#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>

#include "info.h"
#include "smartclass.h"
#include "rete.h"

class Rete;

class Utente : public SmartClass
{
    private:
        bool online;
        bool activate;

        Info infoUser;

        Rete * contacts;

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

        Rete & getContacts();

        std::string getUsername() const;

        void addContact( Utente & );
        void removeContact( const Utente & );
};


class smartptr_utente : public SmartClass::smartptr
{
    public:
        smartptr_utente( Utente * = NULL );

        Utente & operator*() const;
        Utente * operator->() const;
};

#endif // UTENTE_H
