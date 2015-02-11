#include "databasexmlfile.h"

DatabaseXmlFile::DatabaseXmlFile( const QString & name ) : QFile( name )
{}


DatabaseXmlFile::~DatabaseXmlFile()
{}


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

	while( !reader.atEnd() && !reader.hasError() )
	{
		QXmlStreamReader::TokenType token = reader.readNext();

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

    	for( QVector<smartptr_utente>::const_iterator itr = risp.begin();
        	 itr != risp.end();
         	 itr++ )
    	{
        	(*itr)->writeXmlFormat( writer );
    	}

    	writer.writeEndElement();
    	writer.writeEndDocument();

		setFlagModify( false );
	
    	close();
	}
}
