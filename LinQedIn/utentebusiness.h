#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include "utentebasic.h"

class UtenteBusiness : public UtenteBasic
{
    public:
        UtenteBusiness();
        UtenteBusiness( const QString &, const Info & );
        UtenteBusiness( const Utente & );

		LevelAccess::Type typeAccount() const;

		void readXmlFormat( QXmlStreamReader & );
        void writeXmlFormat( QXmlStreamWriter & ) const;
};

#endif // UTENTEBUSINESS_H
