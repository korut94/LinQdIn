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


void UtenteBusiness::readXmlFormat( QXmlStreamReader & reader )
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


void UtenteBusiness::writeXmlFormat( QXmlStreamWriter & writer ) const
{
    writer.writeStartElement( "Utente" ); //Open Utente
    writer.writeAttribute( "type", "Business" );

    writeXmlUserData( writer );

    writer.writeEndElement(); //Close Utente
}
