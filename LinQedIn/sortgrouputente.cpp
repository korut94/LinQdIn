#include "sortgrouputente.h"

bool SortGroupUtente::NameCrescente::operator()
                                     ( const smartptr_entity & a,
                                       const smartptr_entity & b ) const
{
    Info & info_a = a->getInfo();
    Info & info_b = b->getInfo();

    QString nameA = info_a.getPersonal().getNome();
    QString nameB = info_b.getPersonal().getNome();

    return ( nameA.compare( nameB ) <= 0 );
}


bool SortGroupUtente::NameDecrescente::operator()
                                       ( const smartptr_entity & a,
                                         const smartptr_entity & b ) const
{
    Info & info_a = a->getInfo();
    Info & info_b = b->getInfo();

    QString nameA = info_a.getPersonal().getNome();
    QString nameB = info_b.getPersonal().getNome();

    return ( nameA.compare( nameB ) >= 0 );
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
