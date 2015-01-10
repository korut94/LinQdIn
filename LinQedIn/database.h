#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>

#include "frankenstein.h"
#include "hashgrouputente.h"
#include "hashlistutente.h"
#include "query.h"
#include "searchgrouputente.h"
#include "sortgrouputente.h"
#include "utente.h"

class Database
{
    private:
        bool modified;

        HashListUtente<HashGroupUtente::NameCrescente,
                       SortGroupUtente::NameCrescente> entryName;
        HashListUtente<HashGroupUtente::UsernameCrescente,
                       SortGroupUtente::UsernameCrescente> entryUsername;

    public:
        Database();

        bool isPresent( const smartptr_utente & ) const;

        smartptr_utente getUser( Query * ) const;

        void insert( const smartptr_utente & );
        void linkUser( const smartptr_utente &, const smartptr_utente & );
        void modify( const smartptr_utente &, const Info & );
        void remove( const smartptr_utente & );
};

#endif // DATABASE_H
