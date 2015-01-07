#include "utente.h"

Utente::Rete::Rete()
{
}


bool Utente::Rete::isPresent( const Utente & user ) const
{

}


void Utente::Rete::addUser( Utente & user )
{
    users.push_back( smartptr_utente( &user ) );
}


void Utente::Rete::removeUser( const Utente & user )
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


void Utente::addContact( Utente & user )
{
    contacts.addUser( user );
}


void Utente::removeContact( const Utente & user )
{
    if( contacts.isPresent( user ) ) contacts.removeUser( user );
}


std::string Utente::getUsername() const
{
    return username;
}


std::ostream & operator<<( std::ostream & os, const Utente & u )
{
    return ( os << u.infoUser.getNome().toStdString() );
}
