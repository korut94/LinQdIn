#include "utentebasic.h"

UtenteBasic::UtenteBasic()
{
}


UtenteBasic::UtenteBasic( const QString & username, const Info & info )
                          : Utente( username, info ) {}
