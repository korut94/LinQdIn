#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include "utentebasic.h"

class UtenteBusiness : public UtenteBasic
{
    public:
        UtenteBusiness();
        UtenteBusiness( const QString &, const Info & );

		LevelAccess::Type typeAccount() const;
};

#endif // UTENTEBUSINESS_H
