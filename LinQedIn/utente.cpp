#include "utente.h"

Utente::Rete::Rete()
{
}


bool Utente::Rete::isPresent( const smartptr_utente & user ) const
{
    return users.contains( user );
}


void Utente::Rete::addUser( const smartptr_utente & user )
{
    users.push_front( smartptr_utente( user ) );
}


void Utente::Rete::removeUser( const smartptr_utente & user )
{
    users.removeOne( user );
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
    contacts.addUser( user );
}


void Utente::removeContact( const smartptr_utente & user )
{
    if( contacts.isPresent( user ) ) contacts.removeUser( user );
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
