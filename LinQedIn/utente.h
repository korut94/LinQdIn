#ifndef UTENTE_H
#define UTENTE_H

#include "info.h"

class Utente
{
    private:
        Info infoUser;

        std::string password; //class Password?
        std::string username;

    public:
        Utente();
        Utente( const std::string &, const std::string &, const Info & );

        Info & getInfo();
};

#endif // UTENTE_H
