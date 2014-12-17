#include "smartclass.h"

SmartClass::SmartClass() : refCounter( 0 )
{
}


SmartClass::~SmartClass()
{
}


SmartClass::smartptr::smartptr( SmartClass * p ) : ptr( p )
{
    if( ptr != NULL ) ptr->refCounter++;
}


SmartClass::smartptr::smartptr( const smartptr & p ) : ptr( p.ptr )
{
    if( ptr != NULL ) ptr->refCounter++;
}


SmartClass::smartptr::~smartptr()
{
    if( ptr != NULL )
    {
        ptr->refCounter--;

        if( ptr->refCounter == 0 ) delete ptr;
    }
}


bool SmartClass::smartptr::operator==( const smartptr & p ) const
{
    return ( ptr == p.ptr );
}


bool SmartClass::smartptr::operator!=( const smartptr & p ) const
{
    return ( ptr != p.ptr );
}


SmartClass & SmartClass::smartptr::operator*() const
{
    return *ptr;
}


SmartClass * SmartClass::smartptr::operator->() const
{
    return ptr;
}


SmartClass::smartptr & SmartClass::smartptr::operator=( const smartptr & p )
{
    if( this != &p )
    {
        SmartClass * t = ptr;

        ptr = p.ptr;

        if( ptr != NULL ) ptr->refCounter++;

        if( t != NULL )
        {
            t->refCounter--;
            if( t->refCounter == 0 ) delete t;
        }
    }

    return *this;
}







