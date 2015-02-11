#include "hashgrouputente.h"

int HashGroupUtente::NameCrescente::operator()( const Entity & user ) const
{
    QString name = user.getInfo().getPersonal().getNome();
    return name[0].toLatin1() - static_cast<int>( 'A' );
}


int HashGroupUtente::NameDecrescente::operator()( const Entity & user ) const
{
    QString name = user.getInfo().getPersonal().getNome();
    return static_cast<int>( 'Z' ) - name[0].toLatin1();
}


int HashGroupUtente::CognomeCrescente::operator()( const Entity & user ) const
{
    QString cognome = user.getInfo().getPersonal().getCognome();
    return cognome[0].toLatin1() - static_cast<int>( 'A' );
}


int HashGroupUtente::CognomeDecrescente::operator()( const Entity & user )
                                                   const
{
    QString cognome = user.getInfo().getPersonal().getCognome();
    return static_cast<int>( 'Z' ) - cognome[0].toLatin1();
}


int HashGroupUtente::UsernameCrescente::operator()( const Entity & user ) const
{
    QString username = user.getUsername();
    //No case sensitive
    username = username.toLower();

    return username[0].toLatin1() - static_cast<int>( 'a' );
}


int HashGroupUtente::UsernameDecrescente::operator()( const Entity & user )
                                                      const
{
    QString username = user.getUsername();
    //No case sensitive
    username = username.toLower();

    return static_cast<int>( 'Z' ) - username[0].toLatin1();
}
