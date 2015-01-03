#ifndef SORTLIST_H
#define SORTLIST_H

#include <iostream>
#include <QList>

template <typename SortFunction, typename T> class SortList;

template <typename SortFunction, typename T>
std::ostream & operator<< ( std::ostream &, const SortList<SortFunction,T> & );

template <typename SortFunction, typename T>
class SortList : private QList
{
    private:
        SortFunction sort;

    public:
        SortList();

        bool isEmpty() const;

        int size() const;

        void insert( const T & );
        void remove( const T & );

        friend std::ostream & operator<<
        <SortFunction,T>( std::ostream &, const SortList<SortFunction,T> & );
};


template <typename SortFunction, typename T>
SortList<SortFunction,T>::SortList(){}


template <typename SortFunction, typename T>
bool SortList<SortFunction,T>::isEmpty() const
{
    return QList<T>::empty();
}


template <typename SortFunction, typename T>
int SortList<SortFunction,T>::size() const
{
    return QList<T>::size();
}


template <typename SortFunction, typename T>
void SortList<SortFunction,T>::insert( const T & elem )
{
    typename QList<T>::iterator itr = QList<T>::begin();

    while( itr != QList<T>::end() && sort( *itr, elem ) )
    {
        itr++;
    }

    QList<T>::insert( itr, elem );
}


template <typename SortFunction, typename T>
void SortList<SortFunction,T>::remove( const T & elem )
{
    QList<T>::removeAll( elem );
}


template <typename SortFunction, typename T>
std::ostream & operator<< ( std::ostream & os,
                            const SortList<SortFunction,T> & list )
{
    for( typename QList<T>::const_iterator itr = list.constBegin();
         itr != list.constEnd();
         itr++ )
    {
        os << *itr << " ";
    }

    return os;
}
#endif // SORTLIST_H
