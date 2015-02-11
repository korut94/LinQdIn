#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive()
{
}


UtenteExecutive::UtenteExecutive( const QString & username, const Info & info )
                                  : UtenteBusiness( username, info ) {}


UtenteExecutive::UtenteExecutive( const Utente & utente )
                                  : UtenteBusiness( utente ){}


LevelAccess::Type UtenteExecutive::typeAccount() const
{
	return LevelAccess::Executive;
}


void UtenteExecutive::readXmlFormat( QXmlStreamReader & reader )
{
}


void UtenteExecutive::writeXmlFormat( QXmlStreamWriter & writer ) const
{
    writer.writeStartElement( "Utente" ); //Open Utente
    writer.writeAttribute( "type", "Executive" );

    writeXmlUserData( writer );

    writer.writeEndElement(); //Close Utente
}
