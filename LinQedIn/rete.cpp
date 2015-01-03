#include "rete.h"

Rete::Rete()
{
}


Rete::smartptr_rete::smartptr_rete( Rete * r ) : SmartClass::smartptr( r )
{
}


bool Rete::isPresent( const Utente & user ) const
{

}


void Rete::addUser( const Utente & user )
{
    users.push_back( sptr_utente( user ) );
}


void Rete::removeUser( const Utente & user )
{
    QVector<sptr_utente>::ConstIterator itr = users.constBegin();

    bool found = false;

    while( itr != users.constEnd() && !found )
    {
        found = ( user == *itr );

        if( found ) users.erase( itr );
        else itr++;
    }
}


Rete & Rete::smartptr_rete::operator*() const
{
    Rete * r = dynamic_cast<Rete*>( smartptr::operator->() );
    return *r;
}


Rete * Rete::smartptr_rete::operator->() const
{
    Rete * r = dynamic_cast<Rete*>( smartptr::operator->() );
    return r;
}
