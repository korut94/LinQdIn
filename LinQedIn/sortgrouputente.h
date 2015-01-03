#ifndef SORTGROUPUTENTE_H
#define SORTGROUPUTENTE_H

#include "utente.h"

namespace SortGroupUtente
{
    struct AlfabeticoCrescente
    {
        bool operator()( const smartptr_utente &,
                         const smartptr_utente & ) const;
    };

    struct AlfabeticoDecrescente
    {
        bool operator()( const smartptr_utente &,
                         const smartptr_utente & ) const;
    };
}

#endif // SORTGROUPUTENTE_H
