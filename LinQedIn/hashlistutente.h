#ifndef HASHLISTUTENTE_H
#define HASHLISTUTENTE_H

#include <QVector>

#include "searchgrouputente.h"
#include "smartptr_utente.h"
#include "sortlist.h"
#include "utente.h"

template <typename HashFunction, typename SortFunction> class HashListUtente;

template <typename HashFunction, typename SortFunction>
std::ostream & operator<<( std::ostream &,
                           const HashListUtente<HashFunction,SortFunction> & );

template <typename HashFunction, typename SortFunction>
class HashListUtente : private
                       QVector< SortList<SortFunction,smartptr_utente> >
{
    typedef SortList<SortFunction,smartptr_utente> ListUser;

    private:
        HashFunction hash;

    public:
        HashListUtente();

        bool isEmpty() const;
        bool isPresent( const smartptr_utente & ) const;

        int size() const;

        void insert( const smartptr_utente & );
        void remove( const smartptr_utente & );

        friend std::ostream & operator<< <HashFunction,SortFunction>
        ( std::ostream &, const HashListUtente<HashFunction,SortFunction> & );

};

template <typename HashFunction, typename SortFunction>
HashListUtente<HashFunction,SortFunction>::HashListUtente(){}


template <typename HashFunction, typename SortFunction>
bool HashListUtente<HashFunction,SortFunction>::isEmpty() const
{
    return QVector<ListUser>::isEmpty();
}


template <typename HashFunction, typename SortFunction>
bool HashListUtente<HashFunction,SortFunction>::
     isPresent( const smartptr_utente & user ) const
{
    int index = hash( *user );

    if( index > size() - 1 ) return false;
    else
    {
        const ListUser & list = QVector<ListUser>::operator[]( index );
        return list.present( user );
    }
}


template <typename HashFunction, typename SortFunction>
int HashListUtente<HashFunction,SortFunction>::size() const
{
    return QVector<ListUser>::size();
}

/*
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
*/


template <typename HashFunction, typename SortFunction>
void HashListUtente<HashFunction,SortFunction>::
     insert( const smartptr_utente & user )
{
    int index = hash( *user );

    if( index > size() - 1 ) QVector<ListUser>::resize( index + 1 );
    ListUser & list = QVector<ListUser>::operator[]( index );

    list.insert( user);
}


template <typename HashFunction, typename SortFunction>
void HashListUtente<HashFunction,SortFunction>::
     remove( const smartptr_utente & user )
{
    if( isPresent( user ) )
    {
        int index = hash( *user );

        ListUser & list = QVector<ListUser>::operator[]( index );
        list.remove( user );
    }
}


template <typename HashFunction, typename SortFunction>
std::ostream & operator<<( std::ostream & os,
               const HashListUtente<HashFunction,SortFunction> & table )
{
    for( int i = 0; i < table.size(); i++ )
    {
        os << i << " " << table[i] << std::endl;
    }

    return os;
}

#endif // HASHLISTUTENTE_H
