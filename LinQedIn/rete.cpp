#include "rete.h"

Rete::Rete()
{
}


bool Rete::isPresent( const Utente & user ) const
{

}


void Rete::addUser( Utente & user )
{
    users.push_back( smartptr_utente( &user ) );
}


void Rete::removeUser( const Utente & user )
{
    QVector<smartptr_utente>::iterator itr = users.begin();

    bool found = false;

    while( itr != users.end() && !found )
    {
        found = ( user == **itr );

        if( found ) users.erase( itr );
        else itr++;
    }
}
