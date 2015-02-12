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
    QXmlStreamReader::TokenType token = reader.readNext();

    while( !( token == QXmlStreamReader::EndElement &&
              reader.name() == "Utente"  ) )
    {
        if( token == QXmlStreamReader::StartElement )
        {
            if( reader.name() == "username" )
            {
                token = reader.readNext();

                if( token == QXmlStreamReader::Characters )
                    setUsername( reader.text().toString() );

                token = reader.readNext();
            }

            if( reader.name() == "Info" )
            {
                readXmlUserData( reader );
            }
        }

        token = reader.readNext();
    }
}


void UtenteExecutive::writeXmlFormat( QXmlStreamWriter & writer ) const
{
    writer.writeStartElement( "Utente" ); //Open Utente
    writer.writeAttribute( "type", "Executive" );

    writeXmlUserData( writer );

    writer.writeEndElement(); //Close Utente
}
