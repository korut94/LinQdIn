#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include "utentebusiness.h"

class UtenteExecutive : public UtenteBusiness
{
    public:
        UtenteExecutive();
        UtenteExecutive( const QString &, const Info & );
        UtenteExecutive( const Utente & );

		LevelAccess::Type typeAccount() const;

		void readXmlFormat( QXmlStreamReader & );
        void writeXmlFormat( QXmlStreamWriter & ) const;
};

#endif // UTENTEEXECUTIVE_H
