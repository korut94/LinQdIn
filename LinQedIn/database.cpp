#include "database.h"

Database::Category Database::getCategory( const Frankenstein & f ) const
{
    if( !f.getInfo().getPersonal().getNome().isEmpty() ) return Name;
    if( !f.getInfo().getPersonal().getCognome().isEmpty() ) return Surname;
    if( !f.getUsername().isEmpty() ) return Username;
    else return General;
}


Database::Database() : modified( false ) {}


bool Database::isPresent( const smartptr_utente & user ) const
{
    if( user == nullptr ) return false;
    else return entryUsername.isPresent( user );
}


QVector<smartptr_utente> Database::getUser( const Query & query ) const
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
            QVector<smartptr_utente> risp;
            QList<smartptr_utente>::const_iterator itr = general.constBegin();

            while( itr != general.end() )
            {
                if( frankenstein == **itr ) risp.push_back( *itr );
                itr++;
            }

            return risp;
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
    if( a != nullptr && b != nullptr )
    {
        a->getContatti().push_front( b );
        b->getContatti().push_front( a );
    }
}


void Database::modify( const smartptr_utente & user, const Info & infoMod )
{
    if( user != nullptr )
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
    if( user != nullptr )
    {
        user->setActivate( false );

        entryName.remove( user );
        entrySurname.remove( user );
        entryUsername.remove( user );

        general.removeOne( user );
    }
}
