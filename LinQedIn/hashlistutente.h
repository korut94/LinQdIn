#ifndef HASHLISTUTENTE_H
#define HASHLISTUTENTE_H

#include <QVector>

#include "smartptr_utente.h"
#include "sortlist.h"
#include "utente.h"

template <typename HashFunction, typename SortFunction>
class HashListUtente : private
                       QVector< SortList<SortFunction,smartptr_utente> >
{
    typedef SortList<SortFunction,smartptr_utente> listUser;

    private:
        HashFunction hash;

    public:

        HashListUtente();

        bool isEmpty() const;
        bool isPresent( const Utente & ) const;

        Utente & getUser( const Utente & );

        void insert( Utente & );
        void remove( const Utente & );
};

template <typename HashFunction, typename SortFunction>
bool HashListUtente<HashFunction,
                    SortFunction>::isPresent( const Utente & user ) const
{
    int index = hash( user );

    listUser & list = QVector<listUser>::operator[]( index );
    listUser::const_iterator itr = list.constBegin();

    bool found = false;

    while( itr != list.constEnd() && !found )
    {
        found = ( **itr == user );
    }

    return found;
}

#endif // HASHLISTUTENTE_H
