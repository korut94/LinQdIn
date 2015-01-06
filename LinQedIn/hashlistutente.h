#ifndef HASHLISTUTENTE_H
#define HASHLISTUTENTE_H

#include <QVector>

#include "searchgrouputente.h"
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

        int size() const;

        //Utente & getUser( const Utente & );

        void insert( Utente & );
        void remove( const Utente & );
};


template <typename HashFunction, typename SortFunction>
bool HashListUtente<HashFunction,SortFunction>::isEmpty() const
{
    return QVector<listUser>::isEmpty();
}


template <typename HashFunction, typename SortFunction>
bool HashListUtente<HashFunction,
                    SortFunction>::isPresent( const Utente & user ) const
{
    int index = hash( user );

    if( index > size() ) return false;
    else
    {
        listUser & list = QVector<listUser>::operator[]( index );

        return list.present( SearchGroupUtente::UgualeAdUtente( user ) );
    }
}


template <typename HashFunction, typename SortFunction>
int HashListUtente<HashFunction,SortFunction>::size() const
{
    return QVector<listUser>::size();
}


template <typename HashFunction, typename SortFunction>
Utente & HashListUtente<HashFunction,
                        SortFunction>::getUser( const Utente & user )
{
    int index = hash( user );

    listUser & list = QVector<listUser>::operator[]( index );

    bool found = false;
    listUser::iterator itr = list.begin();

    while( itr != list.end() && !found )
    {
        found = ( **itr == user );
        if( !found ) itr++;
    }

    return **itr;
}

#endif // HASHLISTUTENTE_H
