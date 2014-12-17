#include "rete.h"

Rete::Rete()
{
}


Rete::smartptr_rete::smartptr_rete( Rete * r ) : SmartClass::smartptr( r )
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

    while( itr != users.constEnd() && !false )
    {
        std::string username = (*itr)->getUsername();

        found = ( user.getUsername() == username );

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
