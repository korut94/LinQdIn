#ifndef SORTLIST_H
#define SORTLIST_H

#include <iostream>
#include <QList>

template <typename SortFunction, typename T> class SortList;

template <typename SortFunction, typename T>
std::ostream & operator<< ( std::ostream &, const SortList<SortFunction,T> & );

template <typename SortFunction, typename T>
class SortList : private QList<T>
{
    public:
        class iterator : public QList<T>::iterator
        {
            public:
                iterator();
                iterator( const typename QList<T>::iterator & );
        };

        class const_iterator : public QList<T>::const_iterator
        {
            public:
                const_iterator();
                const_iterator( const typename QList<T>::const_iterator & );
        };

    private:
        SortFunction sort;

    public:
        SortList();

        bool compare( const T &, const T & );
        bool isEmpty() const;

        const_iterator constBegin() const;
        const_iterator constEnd() const;

        int size() const;

        iterator begin();
        iterator end();

        void insert( const T & );
        void remove( const T & );

        /*
        friend std::ostream & operator<<
        <SortFunction,T>( std::ostream &, const SortList<SortFunction,T> & );
        */
};

template <typename SortFunction, typename T>
SortList<SortFunction,T>::iterator::iterator(){}


template <typename SortFunction, typename T>
SortList<SortFunction,T>::iterator::iterator(
                                    const typename QList<T>::iterator & itr )
                                    : QList<T>::iterator( itr )
{
}


template <typename SortFunction, typename T>
SortList<SortFunction,T>::const_iterator::const_iterator(){}


template <typename SortFunction, typename T>
SortList<SortFunction,T>::const_iterator::const_iterator(
                          const typename QList<T>::const_iterator & itr )
                          : QList<T>::const_iterator( itr )
{
}


template <typename SortFunction, typename T>
SortList<SortFunction,T>::SortList(){}


template <typename SortFunction, typename T>
bool SortList<SortFunction,T>::compare( const T & a, const T & b )
{
    return sort( a, b );
}


template <typename SortFunction, typename T>
bool SortList<SortFunction,T>::isEmpty() const
{
    return QList<T>::empty();
}


template <typename SortFunction, typename T>
typename SortList<SortFunction,T>::const_iterator
         SortList<SortFunction,T>::constBegin() const
{
    return QList<T>::begin();
}


template <typename SortFunction, typename T>
typename SortList<SortFunction,T>::const_iterator
         SortList<SortFunction,T>::constEnd() const
{
    return QList<T>::end();
}



template <typename SortFunction, typename T>
int SortList<SortFunction,T>::size() const
{
    return QList<T>::size();
}


template <typename SortFunction, typename T>
typename SortList<SortFunction,T>::iterator SortList<SortFunction,T>::begin()
{
    return QList<T>::begin();
}


template <typename SortFunction, typename T>
typename SortList<SortFunction,T>::iterator SortList<SortFunction,T>::end()
{
    return QList<T>::end();
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

/*
 * Tenuta per debug
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
*/
#endif // SORTLIST_H
