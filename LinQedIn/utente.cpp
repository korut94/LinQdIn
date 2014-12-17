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
}


bool Utente::isActivate() const
{
    return activate;
}


bool Utente::isOnline() const
{
    return online;
}


Info & Utente::getInfo()
{
    return infoUser;
}


Rete & Utente::getContacts()
{
    return *contacts;
}


void Utente::addContact( const Utente & user )
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


Utente::smartptr_utente::smartptr_utente( Utente * p )
                                          : SmartClass::smartptr( p )
{
}


Utente & Utente::smartptr_utente::operator*() const
{
    Utente * r = dynamic_cast<Utente*>( smartptr::operator->() );
    return *r;
}


Utente * Utente::smartptr_utente::operator->() const
{
    Utente * p = dynamic_cast<Utente*>( smartptr::operator->() );
    return p;
}
