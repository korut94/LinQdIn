#include "database.h"

Database::Database() : modified( false ) {}


bool Database::isPresent( const smartptr_utente & user ) const
{
    return entryUsername.isPresent( user );
}


smartptr_utente Database::getUser( Query * query ) const
{
    Frankenstein frankenstein;
    query->compose( frankenstein );

    return entryUsername.getUser( frankenstein );
}

