#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness()
{
}


UtenteBusiness::UtenteBusiness( const QString & username, const Info & info )
                                : UtenteBasic( username, info ) {}


UtenteBusiness::UtenteBusiness( const Utente & utente ) : UtenteBasic( utente )
{
}


LevelAccess::Type UtenteBusiness::typeAccount() const
{
	return LevelAccess::Business;
}


void UtenteBusiness::writeXmlFormat( QXmlStreamWriter & writer ) const
{
    writer.writeStartElement( "Utente" ); //Open Utente
    writer.writeAttribute( "type", "Business" );

    writeXmlUserData( writer );

    writer.writeEndElement(); //Close Utente
}
