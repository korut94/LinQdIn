#include "searchgrouputente.h"

SearchGroupUtente::ByUsername::ByUsername( const QString & u ) : username( u )
{}

void SearchGroupUtente::ByUsername::compose( Frankenstein & path ) const
{
    path.setUsername( username );
}


SearchGroupUtente::ByNameAndSurname::ByNameAndSurname( const QString & n,
                                                       const QString & s )
                                                       : name( n ),
                                                         surname( s )
{}

void SearchGroupUtente::ByNameAndSurname::compose( Frankenstein & path ) const
{
    path.getInfo().getPersonal().setNome( name );
    path.getInfo().getPersonal().setCognome( surname );
}
