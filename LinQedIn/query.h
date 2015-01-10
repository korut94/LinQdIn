#ifndef QUERY_H
#define QUERY_H

#include "frankenstein.h"

class Query
{
    public:
        Query();

        virtual compose( Frankenstein & ) const = 0;
};

#endif // QUERY_H
