#include "searchgrouputente.h"

SearchGroupUtente::UgualeAdUtente::UgualeAdUtente( const Utente & u )
                                                   : user( u ){}


bool SearchGroupUtente::UgualeAdUtente::operator()
                                        ( const smartptr_utente & u ) const
{
    return ( u == NULL ) ? false : ( user == *u );
}
