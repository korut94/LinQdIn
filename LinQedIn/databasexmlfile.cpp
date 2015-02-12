#include "databasexmlfile.h"

DatabaseXmlFile::DatabaseXmlFile( const QString & name ) : QFile( name )
{}


DatabaseXmlFile::~DatabaseXmlFile()
{}


QVector<smartptr_utente>::iterator
DatabaseXmlFile::foundUserBuffer( QVector<smartptr_utente> & buffer,
                                  const QString & username )
{
    bool found = false;
    QVector<smartptr_utente>::iterator itr = buffer.begin();

    while( itr != buffer.end() && !found )
    {
        if( (*itr)->getUsername() == username ) found = true;
        else itr++;
    }

    return itr;
}


void DatabaseXmlFile::load()
{
	setFlagLoad( false );

	open( QIODevice::ReadOnly );

	/*
	 * L'uso del vector serve nel caso ci sia un errore nel parsing 
	 * durante il caricamento
	*/
	QVector<smartptr_utente> usersLoadFile;

	QXmlStreamReader reader( this );

    QXmlStreamReader::TokenType token;

	while( !reader.atEnd() && !reader.hasError() )
	{
        token = reader.readNext();

		if( token == QXmlStreamReader::StartElement )
		{
			if( reader.name() == "Utente" )
			{
				smartptr_utente user;

				if( reader.attributes().value( "type" ) == "Basic" )
					user = new UtenteBasic();

				else if( reader.attributes().value( "type" ) == "Business" )
					user = new UtenteBusiness();

				else if( reader.attributes().value( "type" ) == "Executive" )
					user = new UtenteExecutive();

				user->readXmlFormat( reader );
				usersLoadFile.push_back( user );
			}

            if( reader.name() == "friends" )
            {
                QString username =
                        reader.attributes().value( "user" ).toString();

                QVector<smartptr_utente>::iterator
                    itrUser = foundUserBuffer( usersLoadFile, username );

                //if( !found ) return;

                while( !( token == QXmlStreamReader::EndElement &&
                          reader.name() == "friends" ) )
                {
                    if( reader.name() == "friend" )
                    {
                        token = reader.readNext();

                        if( token == QXmlStreamReader::Characters )
                        {
                            username = reader.text().toString();

                            QVector<smartptr_utente>::iterator
                                itrFriend = foundUserBuffer( usersLoadFile,
                                                             username );

                            (*itrUser)->addContact( *itrFriend );
                            (*itrFriend)->addContact( *itrUser );
                        }

                        token = reader.readNext();
                    }

                    token = reader.readNext();
                }
            }
		}
	}

	if( reader.hasError() ) std::cout << reader.errorString().toStdString() << std::endl;
	else
	{
		for( QVector<smartptr_utente>::const_iterator 
									   itr = usersLoadFile.begin();	
			 itr != usersLoadFile.end();
			 itr++ )
		{
			insert( *itr );
		}
		
		setFlagLoad( true );
	}	

	close();
}


void DatabaseXmlFile::save()
{
	if( isModified() )
	{ 
    	if( !isLoaded() ) QFile::remove( fileName() ); //sovrascrittura

    	open( QIODevice::WriteOnly );

    	QXmlStreamWriter writer( this );
    	writer.setAutoFormatting( true );

    	writer.writeStartDocument();
    	writer.writeStartElement( "Database" );

    	QVector<smartptr_utente> risp = getUsers( SearchGroupUtente::All() );

        QVector<smartptr_utente>::const_iterator itr = risp.begin();

        for( ; itr != risp.end(); itr++ )
    	{
        	(*itr)->writeXmlFormat( writer );
    	}

        writer.writeComment( "Lista relazioni tra utenti" );

        for( itr = risp.begin(); itr != risp.end(); itr++ )
        {
            writer.writeStartElement( "friends" );
            writer.writeAttribute( "user", (*itr)->getUsername() );

            const Utente::Rete & contatti = (*itr)->getContatti();

            for( Utente::Rete::const_iterator itr = contatti.begin();
                 itr != contatti.end();
                 itr++ )
            {
                writer.writeTextElement( "friend", (*itr)->getUsername() );
            }

            writer.writeEndElement();
        }

    	writer.writeEndElement();
    	writer.writeEndDocument();

		setFlagModify( false );
	
    	close();
	}
}
