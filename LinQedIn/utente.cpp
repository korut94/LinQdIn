#include "utente.h"

Utente::Utente()
{
}


Utente::Utente( const std::string & user,
                const std::string & pass,
                const Info & info )
                : username( user ), password( pass ), infoUser( info )
{
}


Info & Utente::getInfo()
{
    return infoUser;
}
