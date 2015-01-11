#ifndef SMARTPTR_ENTITY_H
#define SMARTPTR_ENTITY_H

#include "entity.h"
#include "smartclass.h"

class smartptr_entity : public SmartClass::smartptr
{
    public:
        smartptr_entity( Entity * = NULL );

        Entity & operator*() const;
        Entity * operator->() const;
};

#endif // SMARTPTR_ENTITY_H
