#include "utente.h"

Utente::Utente()
{
}


Utente::Utente( const std::string & user,
                const std::string & pass,
                const Info & info )
                : username( user ),
                  password( pass ),
                  infoUser( info )
{
}


Utente::~Utente()
{
    delete contacts;
}


bool Utente::isActivate() const
{
    return activate;
}


bool Utente::isOnline() const
{
    return online;
}


bool Utente::operator==( const Utente & user ) const
{
    return ( username == user.getUsername() );
}


bool Utente::operator!=( const Utente & user ) const
{
    return ( username != user.getUsername() );
}


Info & Utente::getInfo()
{
    return infoUser;
}


Rete & Utente::getContacts()
{
    return *contacts;
}


void Utente::addContact( Utente & user )
{
    contacts->addUser( user );
}


void Utente::removeContact( const Utente & user )
{
    if( contacts->isPresent( user ) ) contacts->removeUser( user );
}


std::string Utente::getUsername() const
{
    return username;
}


smartptr_utente::smartptr_utente( Utente * p )
                                          : SmartClass::smartptr( p )
{
}


Utente & smartptr_utente::operator*() const
{
    Utente * r = dynamic_cast<Utente*>( smartptr::operator->() );
    return *r;
}


Utente * smartptr_utente::operator->() const
{
    Utente * p = dynamic_cast<Utente*>( smartptr::operator->() );
    return p;
}
