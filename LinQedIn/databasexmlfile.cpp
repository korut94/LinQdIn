#include "databasexmlfile.h"

DatabaseXmlFile::DatabaseXmlFile( const QString & name )
                                  : DatabaseFile( name ),
                                    reader( this ),
                                    writer( this )
{
}


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


bool DatabaseXmlFile::load()
{
    setFlagLoad( false );

    if( !open( QIODevice::ReadOnly ) ) return true;

    /*
     * L'uso del vector serve nel caso ci sia un errore nel parsing
     * durante il caricamento
    */
    QVector<smartptr_utente> usersLoadFile;

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

    bool state;

    if( reader.hasError() ) state = false;
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
        //Il caricamento del db non costituisce una reale modifica
        setFlagModify( false );

        state = true;
    }

    close();

    return state;
}


bool DatabaseXmlFile::save()
{
    if( !isLoaded() ) QFile::remove( fileName() ); //sovrascrittura

    open( QIODevice::WriteOnly );

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
            //Elimina i contatti rimossi da LinQedIn
            if( (*itr)->isActivate() )
                writer.writeTextElement( "friend", (*itr)->getUsername() );
        }

        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndDocument();

    setFlagModify( false );

    close();

	return true;
}


QString DatabaseXmlFile::error() const
{
    return reader.errorString();
}
