#ifndef HASHGROUPUTENTE_H
#define HASHGROUPUTENTE_H

#include <QLocale>
#include <QString>

#include "utente.h"

namespace HashGroupUtente
{
    struct AlfabeticoCreUpCase
    {
        int operator() ( const QString & );
    };

    struct AlfabeticoDecUpCase
    {
        int operator() ( const QString & );
    };
}

#endif // HASHGROUPUTENTE_H
