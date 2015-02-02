#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness()
{
}


UtenteBusiness::UtenteBusiness( const QString & username, const Info & info )
                                : UtenteBasic( username, info ) {}


LevelAccess::Type UtenteBusiness::typeAccount() const
{
	return LevelAccess::Business;
}
