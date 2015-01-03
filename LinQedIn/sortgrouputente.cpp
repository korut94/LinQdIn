#include "sortgrouputente.h"

bool SortGroupUtente::AlfabeticoCrescente::operator()
                      ( const smartptr_utente & a, const smartptr_utente & b )
                      const
{
    Info & info_a = a->getInfo();
    Info & info_b = b->getInfo();

    return ( info_a.getNome().compare( info_b.getNome() ) < 0 );
}


bool SortGroupUtente::AlfabeticoDecrescente::operator()
                      ( const smartptr_utente & a, const smartptr_utente & b )
                      const
{
    Info & info_a = a->getInfo();
    Info & info_b = b->getInfo();

    return ( info_a.getNome().compare( info_b.getNome() ) > 0 );
}
