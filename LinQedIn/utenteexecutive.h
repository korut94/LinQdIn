#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include "utentebusiness.h"

class UtenteExecutive : public UtenteBusiness
{
    public:
        UtenteExecutive();
        UtenteExecutive( const QString &, const Info & );

		LevelAccess::Type typeAccount() const;
};

#endif // UTENTEEXECUTIVE_H
