#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <QList>

#include "frankenstein.h"
#include "hashgrouputente.h"
#include "hashlistutente.h"
#include "query.h"
#include "searchgrouputente.h"
#include "utente.h"

class Database
{
    private:
        enum Category
        {
            Name,
            Surname,
            Username,
            General
        };

        bool modified;

        HashListUtente<HashGroupUtente::NameCrescente> entryName;
        HashListUtente<HashGroupUtente::CognomeCrescente> entrySurname;
        HashListUtente<HashGroupUtente::UsernameCrescente> entryUsername;

        QList<smartptr_utente> general;

        Category getCategory( const Frankenstein & ) const;

    protected:
        void setModified( bool );

    public:
        Database();

        bool isPresent( const smartptr_utente & ) const;

        QVector<smartptr_utente> getUsers( const Query & ) const;

        smartptr_utente recoveryUser( const smartptr_utente & ) const;

        void insert( const smartptr_utente & );
        void linkUser( const smartptr_utente &, const smartptr_utente & );
        virtual void loadDB() = 0;
        void modify( const smartptr_utente &, const Info & );
        void remove( const smartptr_utente & );
        virtual void saveDB() = 0;
        void unlinkUser( const smartptr_utente &, const smartptr_utente & );
};

#endif // DATABASE_H
