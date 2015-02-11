#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include "utente.h"

class UtenteBasic : public Utente
{
    public:
        UtenteBasic();
        UtenteBasic( const QString &, const Info & );
        UtenteBasic( const Utente & );

		LevelAccess::Type typeAccount() const;

		void readXmlFormat( QXmlStreamReader & );
        void writeXmlFormat( QXmlStreamWriter & ) const;
};

#endif // UTENTEBASIC_H
