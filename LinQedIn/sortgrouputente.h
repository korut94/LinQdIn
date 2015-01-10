#ifndef SORTGROUPUTENTE_H
#define SORTGROUPUTENTE_H

#include "utente.h"

namespace SortGroupUtente
{
    struct NameCrescente
    {
        bool operator()( const smartptr_utente &,
                         const smartptr_utente & ) const;
    };

    struct NameDecrescente
    {
        bool operator()( const smartptr_utente &,
                         const smartptr_utente & ) const;
    };

    struct UsernameCrescente
    {
        bool operator()( const smartptr_utente &,
                         const smartptr_utente & ) const;
    };

    struct UsernameDecrescente
    {
        bool operator()( const smartptr_utente &,
                         const smartptr_utente & ) const;
    };
}

#endif // SORTGROUPUTENTE_H
