#include "sortgrouputente.h"

bool SortGroupUtente::NameCrescente::operator()
                                     ( const smartptr_entity & a,
                                       const smartptr_entity & b ) const
{
    Info & info_a = a->getInfo();
    Info & info_b = b->getInfo();

    return ( info_a.getNome().compare( info_b.getNome() ) <= 0 );
}


bool SortGroupUtente::NameDecrescente::operator()
                                       ( const smartptr_entity & a,
                                         const smartptr_entity & b ) const
{
    Info & info_a = a->getInfo();
    Info & info_b = b->getInfo();

    return ( info_a.getNome().compare( info_b.getNome() ) >= 0 );
}


bool SortGroupUtente::UsernameCrescente::operator()
                                         ( const smartptr_entity & a,
                                           const smartptr_entity & b ) const
{
    return ( a->getUsername().compare( b->getUsername(),
                                       Qt::CaseInsensitive ) >= 0 );
}


bool SortGroupUtente::UsernameDecrescente::operator()
                                           ( const smartptr_entity & a,
                                             const smartptr_entity & b ) const
{
    return ( a->getUsername().compare( b->getUsername(),
                                       Qt::CaseInsensitive ) <= 0 );
}
