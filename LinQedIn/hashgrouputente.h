#ifndef HASHGROUPUTENTE_H
#define HASHGROUPUTENTE_H

#include <QLocale>
#include <QString>
#include <string>

#include "utente.h"

namespace HashGroupUtente
{
    struct CognomeCrescente
    {
        int operator()( const Entity & ) const;
    };

    struct CognomeDecrescente
    {
        int operator()( const Entity & ) const;
    };

    struct NameCrescente
    {
        int operator()( const Entity & ) const;
    };

    struct NameDecrescente
    {
        int operator()( const Entity & ) const;
    };

    struct UsernameCrescente
    {
        int operator()( const Entity & ) const;
    };

    struct UsernameDecrescente
    {
        int operator()( const Entity & ) const;
    };
}

#endif // HASHGROUPUTENTE_H
