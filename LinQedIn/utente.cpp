#include "utente.h"

Utente::Rete::Rete()
{
}


bool Utente::Rete::isPresent( const Utente & user ) const
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


const Info & Utente::getInfo() const
{
    return infoUser;
}


void Utente::addContact( const smartptr_utente & user )
{
    contacts.addUser( user );
}


void Utente::removeContact( const smartptr_utente & user )
{
    if( contacts.isPresent( user ) ) contacts.removeUser( user );
}


QString Utente::getUsername() const
{
    return username;
}


std::ostream & operator<<( std::ostream & os, const Utente & u )
{
    return ( os << u.infoUser.getNome().toStdString() );
}
