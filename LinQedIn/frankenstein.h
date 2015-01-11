#ifndef FRANKENSTEIN_H
#define FRANKENSTEIN_H

#include "utente.h"

class Frankenstein : public Entity
{
    public:
        Utente::Rete contatti;

        Frankenstein();
        Frankenstein( const QString &, const QString &, const Info & );
        Frankenstein( const Utente & );

        bool operator==( const Frankenstein & ) const;
        bool operator!=( const Frankenstein & ) const;
};

#endif // FRANKENSTEIN_H
