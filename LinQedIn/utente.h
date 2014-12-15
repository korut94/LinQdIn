#ifndef UTENTE_H
#define UTENTE_H

#include "info.h"

class Utente
{
    private:
        Info info;

        std::string password; //class Password?
        std::string username;

    public:
        Utente( const std::string &, const std::string &, const Info & );

        Info & getInfo() const;
        const Info & getInfoConst() const;
};

#endif // UTENTE_H
