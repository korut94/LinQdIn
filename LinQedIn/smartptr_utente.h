#ifndef SMARTPTR_UTENTE_H
#define SMARTPTR_UTENTE_H

#include "smartclass.h"
#include "utente.h"

class Utente;

class smartptr_utente : public SmartClass::smartptr
{
    public:
        smartptr_utente( Utente * = NULL );

        Utente & operator*() const;
        Utente * operator->() const;
};

#endif // SMARTPTR_UTENTE_H
