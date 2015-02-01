#include "utente.h"

Utente::Rete::Rete()
{
}


bool Utente::Rete::contains( const smartptr_utente & t ) const
{
    bool found = false;

    QList<smartptr_utente>::const_iterator itr = begin();

    while( itr != end() && !found )
    {
        found = ( **itr == *t );
        itr++;
    }

    return found;
}


bool Utente::Rete::removeOne( const smartptr_utente & t )
{
    bool found = false;

    QList<smartptr_utente>::iterator itr = begin();

    while( itr != end() && !found )
    {
        if( ( found = ( **itr == *t ) ) ) erase( itr );
        else itr++;
    }

    return found;
}


Utente::Utente()
{
}


Utente::Utente( const QString & user,
                const Info & info )
                : Entity( user, info ) {}


Utente::~Utente()
{
}


bool Utente::isActivate() const
{
    return activate;
}


bool Utente::isOnline() const
{
    return online;
}


Utente::Rete & Utente::getContatti()
{
    return contacts;
}


const Utente::Rete & Utente::getContatti() const
{
    return contacts;
}


void Utente::addContact( const smartptr_utente & user )
{
    if( user != nullptr ) contacts.push_front( user );
}


void Utente::removeContact( const smartptr_utente & user )
{
    contacts.removeOne( user );
}


void Utente::setActivate( bool set )
{
    activate = set;
}


void Utente::setOnline( bool set )
{
    online = set;
}


std::ostream & operator<<( std::ostream & os, const Utente & u )
{
    return ( os << u.getInfo().getPersonal().getNome().toStdString() );
}
