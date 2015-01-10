#ifndef HASHGROUPUTENTE_H
#define HASHGROUPUTENTE_H

#include <QLocale>
#include <QString>
#include <string>

#include "utente.h"

namespace HashGroupUtente
{
    struct NameCrescente
    {
        int operator()( const Utente & ) const;
    };

    struct NameDecrescente
    {
        int operator()( const Utente & ) const;
    };

    struct UsernameCrescente
    {
        int operator()( const Utente & ) const;
    };

    struct UsernameDecrescente
    {
        int operator()( const Utente & ) const;
    };
}

#endif // HASHGROUPUTENTE_H
