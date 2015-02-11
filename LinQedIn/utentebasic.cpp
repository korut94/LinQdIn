#include "utentebasic.h"

UtenteBasic::UtenteBasic()
{
}


UtenteBasic::UtenteBasic( const QString & username, const Info & info )
                          : Utente( username, info ) {}


UtenteBasic::UtenteBasic( const Utente & utente ) : Utente( utente ) {}


LevelAccess::Type UtenteBasic::typeAccount() const
{
	return LevelAccess::Basic;
}


void UtenteBasic::readXmlFormat( QXmlStreamReader & reader )
{
	QXmlStreamReader::TokenType token = reader.readNext();

	if( token == QXmlStreamReader::StartElement && 
		reader.name() == "username" ) 
	{
		setUsername( reader.text().toString() );

		token = reader.readNext();
	
		readXmlUserData( reader );
	}
	else reader.raiseError( "Error parsing file, expected 'username' token" );
}


void UtenteBasic::writeXmlFormat( QXmlStreamWriter & writer ) const
{
    writer.writeStartElement( "Utente" ); //Open Utente
    writer.writeAttribute( "type", "Basic" );

    writeXmlUserData( writer );

    writer.writeEndElement(); //Close Utente
}
