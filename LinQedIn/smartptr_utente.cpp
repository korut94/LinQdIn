#include "smartptr_utente.h"

smartptr_utente::smartptr_utente( Utente * p )
                                  : smartptr_entity( p )
{
}


Utente & smartptr_utente::operator*() const
{
    Utente * r = dynamic_cast<Utente*>( smartptr_entity::operator->() );
    return *r;
}


Utente * smartptr_utente::operator->() const
{
    Utente * p = dynamic_cast<Utente*>( smartptr_entity::operator->() );
    return p;
}

