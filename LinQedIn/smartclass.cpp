#include "smartclass.h"

SmartClass::SmartClass() : refCounter( 0 )
{
}


SmartClass::smartptr( SmartClass * p ) : ptr( p )
{
    if( ptr != NULL ) ptr->refCounter++;
}
