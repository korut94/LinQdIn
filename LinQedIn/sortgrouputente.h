#ifndef SORTGROUPUTENTE_H
#define SORTGROUPUTENTE_H

#include "smartptr_entity.h"

namespace SortGroupUtente
{
    struct NameCrescente
    {
        bool operator()( const smartptr_entity &,
                         const smartptr_entity & ) const;
    };

    struct NameDecrescente
    {
        bool operator()( const smartptr_entity &,
                         const smartptr_entity & ) const;
    };

    struct UsernameCrescente
    {
        bool operator()( const smartptr_entity &,
                         const smartptr_entity & ) const;
    };

    struct UsernameDecrescente
    {
        bool operator()( const smartptr_entity &,
                         const smartptr_entity & ) const;
    };
}

#endif // SORTGROUPUTENTE_H
