#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive()
{
}


UtenteExecutive::UtenteExecutive( const QString & username, const Info & info )
                                  : UtenteBusiness( username, info ) {}


LevelAccess::Type UtenteExecutive::typeAccount() const
{
	return LevelAccess::Executive;
}
