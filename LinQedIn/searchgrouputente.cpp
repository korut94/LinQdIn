#include "searchgrouputente.h"

void SearchGroupUtente::All::compose( Frankenstein & path ) const
{

}


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


SearchGroupUtente::ByInfo::ByInfo( const Info & i ) : info( i ) {}


void SearchGroupUtente::ByInfo::compose( Frankenstein & path ) const
{
    path = Frankenstein( "", info );
}
