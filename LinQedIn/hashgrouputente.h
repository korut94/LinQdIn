#ifndef HASHGROUPUTENTE_H
#define HASHGROUPUTENTE_H

#include <QLocale>
#include <QString>
#include <string>

#include "utente.h"

namespace HashGroupUtente
{
    struct AlfabeticoCreUpCase
    {
        int operator() ( const Utente & ) const;
    };

    struct AlfabeticoDecUpCase
    {
        int operator() ( const Utente & ) const;
    };
}

#endif // HASHGROUPUTENTE_H
