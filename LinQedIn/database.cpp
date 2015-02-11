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


QVector<smartptr_utente> Database::getUsers( const Query & query ) const
{
    Frankenstein frankenstein;
    query.compose( frankenstein );

    switch( getCategory( frankenstein ) )
    {
        case Name : return entryName.getUsers( frankenstein );
        case Surname : return entrySurname.getUsers( frankenstein );
        case Username : return entryUsername.getUsers( frankenstein );

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


smartptr_utente Database::recoveryUser( const smartptr_utente & user ) const
{
    if( user != nullptr )
    {
        QVector<smartptr_utente> risp =
            getUsers( SearchGroupUtente::ByUsername( user->getUsername() ) );

        if( risp.size() > 0 ) return risp[0];
        else return nullptr;
    }

    else return nullptr;
}


void Database::insert( const smartptr_utente & user )
{
    if( user != nullptr )
    {
        entryName.insert( user );
        entrySurname.insert( user );
        entryUsername.insert( user );

        general.push_front( user );

        modified = true;
    }
}


void Database::linkUser( const smartptr_utente & a, const smartptr_utente & b )
{
    if( a != nullptr && b != nullptr )
    {
        a->addContact( b );
        b->addContact( a );

        modified = true;
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

        modified = true;
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

        modified = true;
    }
}


void Database::setModified( bool state )
{
    modified = state;
}


void Database::unlinkUser( const smartptr_utente & a,
                           const smartptr_utente & b )
{
    if( a != nullptr && b != nullptr )
    {
        a->removeContact( b );
        b->removeContact( a );

        modified = true;
    }
}
