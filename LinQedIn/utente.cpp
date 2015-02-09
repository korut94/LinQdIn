#include "utente.h"

Utente::Rete::Rete()
{
}


bool Utente::Rete::isPresent( const smartptr_utente & t ) const
{
    bool found = false;

    QList<smartptr_utente>::const_iterator itr =
                                           QList<smartptr_utente>::begin();

    while( itr != QList<smartptr_utente>::end() && !found )
    {
        found = ( **itr == *t );
        itr++;
    }

    return found;
}


QVector<smartptr_utente> Utente::Rete::toVector() const
{
    return QList<smartptr_utente>::toVector();
}


void Utente::Rete::add( const smartptr_utente & t )
{
    if( !isPresent( t ) ) QList<smartptr_utente>::push_front( t );
}


void Utente::Rete::remove( const smartptr_utente & t )
{
    bool found = false;

    QList<smartptr_utente>::iterator itr = QList<smartptr_utente>::begin();

    while( itr != QList<smartptr_utente>::end() && !found )
    {
        if( **itr == *t )
        {
            QList<smartptr_utente>::erase( itr );
            found = true;
        }
        else itr++;
    }
}


Utente::Utente()
{
}


Utente::Utente( const QString & user,
                const Info & info )
                : online( false ), activate( false ), Entity( user, info )
{
}


Utente::~Utente()
{
}


bool Utente::isActivate() const
{
    return activate;
}


bool Utente::isFriendOf( const smartptr_utente & user ) const
{
    return contacts.isPresent( user );
}


bool Utente::isOnline() const
{
    return online;
}


const Utente::Rete & Utente::getContatti() const
{
    return contacts;
}


void Utente::addContact( const smartptr_utente & user )
{
    if( user != nullptr ) contacts.add( user );
}


void Utente::removeContact( const smartptr_utente & user )
{
    contacts.remove( user );
}


void Utente::setActivate( bool set )
{
    activate = set;
}


void Utente::setOnline( bool set )
{
    online = set;
}
