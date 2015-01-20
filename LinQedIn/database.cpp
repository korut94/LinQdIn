#include "database.h"

Database::Category Database::getCategory( const Frankenstein & f ) const
{
    if( !f.getInfo().getNome().isEmpty() ) return Name;
    if( !f.getInfo().getCognome().isEmpty() ) return Surname;
    if( !f.getUsername().isEmpty() ) return Username;
    else return General;
}


Database::Database() : modified( false ) {}


bool Database::isPresent( const smartptr_utente & user ) const
{
    if( user == NULL ) return false;
    else return entryUsername.isPresent( user );
}


smartptr_utente Database::getUser( const Query & query ) const
{
    Frankenstein frankenstein;
    query.compose( frankenstein );

    switch( getCategory( frankenstein ) )
    {
        case Name : return entryName.getUser( frankenstein );
        case Surname : return entrySurname.getUser( frankenstein );
        case Username : return entryUsername.getUser( frankenstein );

        case General :
        {
            bool found = false;

            QList<smartptr_utente>::const_iterator itr = general.constBegin();

            while( itr != general.end() && !found )
            {
                if( frankenstein == **itr ) found = true;
                else itr++;
            }

            if( found ) return *itr;
            else return NULL;
        }
    }
}


void Database::insert( const smartptr_utente & user )
{
    entryName.insert( user );
    entrySurname.insert( user );
    entryUsername.insert( user );

    general.push_front( user );
}


void Database::linkUser( const smartptr_utente & a, const smartptr_utente & b )
{
    if( a != NULL && b != NULL ) a->getContatti().addUser( b );
}


void Database::modify( const smartptr_utente & user, const Info & infoMod )
{
    if( user != NULL )
    {
        //L'utente non verra cancellato dalla memoria perchè è puntato almeno
        //dallo smartptr_utente passato come parametro
        remove( user );
        user->getInfo() = infoMod;

        insert( user );
    }
}


void Database::remove( const smartptr_utente & user )
{
    if( user != NULL )
    {
        user->setActivate( false );

        entryName.remove( user );
        entrySurname.remove( user );
        entryUsername.remove( user );

        general.removeOne( user );
    }
}
