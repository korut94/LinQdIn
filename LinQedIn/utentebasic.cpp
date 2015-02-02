#include "utentebasic.h"

UtenteBasic::UtenteBasic()
{
}


UtenteBasic::UtenteBasic( const QString & username, const Info & info )
                          : Utente( username, info ) {}


LevelAccess::Type UtenteBasic::typeAccount() const
{
	return LevelAccess::Basic;
}
