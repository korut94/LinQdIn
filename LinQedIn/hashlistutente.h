#ifndef HASHLISTUTENTE_H
#define HASHLISTUTENTE_H

#include <QVector>

#include "searchgrouputente.h"
#include "smartptr_utente.h"
#include "utente.h"

template <typename HashFunction>
class HashListUtente : private QVector< QList<smartptr_utente> >
{
    typedef QList<smartptr_utente> ListUser;

    private:
        HashFunction hash;

    public:
        HashListUtente();

        bool isEmpty() const;
        bool isPresent( const smartptr_utente & ) const;

        int size() const;

        QVector<smartptr_utente> getUser( const Frankenstein & ) const;

        void insert( const smartptr_utente & );
        void remove( const smartptr_utente & );
};


template <typename HashFunction>
HashListUtente<HashFunction>::HashListUtente(){}


template <typename HashFunction>
bool HashListUtente<HashFunction>::isEmpty() const
{
    return QVector<ListUser>::isEmpty();
}


template <typename HashFunction>
bool HashListUtente<HashFunction>::
     isPresent( const smartptr_utente & user ) const
{
    if( user == nullptr ) return false;
    else
    {
        int index = hash( *user );

        if( index > size() - 1 ) return false;
        else
        {
            const ListUser & list = QVector<ListUser>::operator[]( index );
            return list.contains( user );
        }
    }
}


template <typename HashFunction>
int HashListUtente<HashFunction>::size() const
{
    return QVector<ListUser>::size();
}


template <typename HashFunction>
QVector<smartptr_utente> HashListUtente<HashFunction>::
                getUser( const Frankenstein & path ) const
{
    int index = hash( path );

    QVector<smartptr_utente> risp;

    if( index > size() - 1 ) return risp;
    else
    {
        const ListUser & list = QVector<ListUser>::operator[]( index );
        typename ListUser::const_iterator itr = list.begin();

        while( itr != list.end() )
        {
            if( path == **itr ) risp.push_back( *itr );
            itr++;
        }

        return risp;
    }
}


template <typename HashFunction>
void HashListUtente<HashFunction>::insert( const smartptr_utente & user )
{
    if( user != nullptr )
    {
        int index = hash( *user );

        if( index > size() - 1 ) QVector<ListUser>::resize( index + 1 );
        ListUser & list = QVector<ListUser>::operator[]( index );

        list.push_front( user );
    }
}


template <typename HashFunction>
void HashListUtente<HashFunction>::remove( const smartptr_utente & user )
{
    if( user != nullptr )
    {
        int index = hash( *user );

        if( index < size() )
        {
            ListUser & list = QVector<ListUser>::operator[]( index );
            list.removeOne( user );
        }
    }
}

#endif // HASHLISTUTENTE_H
