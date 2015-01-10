#include "searchgrouputente.h"

SearchGroupUtente::ByUsername::ByUsername( const QString & u ) : username( u )
{}

void SearchGroupUtente::ByUsername::compose( Frankenstein & path ) const
{
    path.setUsername( username );
}
