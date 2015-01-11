#include "smartptr_entity.h"

smartptr_entity::smartptr_entity( Entity * e )
                                  : SmartClass::smartptr( e ) {}


Entity & smartptr_entity::operator*() const
{
    Entity * e = static_cast<Entity*>( smartptr::operator->() );
    return *e;
}


Entity * smartptr_entity::operator->() const
{
    Entity * e = static_cast<Entity*>( smartptr::operator->() );
    return e;
}
