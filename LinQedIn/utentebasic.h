#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include "utente.h"

class UtenteBasic : public Utente
{
    public:
        UtenteBasic();
        UtenteBasic( const QString &, const Info & );

		LevelAccess::Type typeAccount() const;
};

#endif // UTENTEBASIC_H
