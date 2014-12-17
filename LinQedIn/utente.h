#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>

#include "info.h"
#include "smartclass.h"

class Utente : public SmartClass
{
    private:
        bool online;
        bool activate;

        Info infoUser;

        std::string password; //class Password?
        std::string username;

    public:
        Utente();
        Utente( const std::string &, const std::string &, const Info & );
        virtual ~Utente();

        bool isActivate() const;
        bool isOnline() const;

        Info & getInfo();

        class smartptr_utente : public SmartClass::smartptr
        {
            public:
                smartptr_utente( Utente * = NULL );

                Utente & operator*() const;
                Utente * operator->() const;
        };
};

typedef Utente::smartptr_utente sptr_utente;

#endif // UTENTE_H
