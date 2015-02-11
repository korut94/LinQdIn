#include "databasexmlfile.h"

DatabaseXmlFile::DatabaseXmlFile( const QString & name ) : QFile( name )
{}


DatabaseXmlFile::~DatabaseXmlFile()
{}


void DatabaseXmlFile::load()
{

}


void DatabaseXmlFile::save()
{
	if( !isModified() )
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
