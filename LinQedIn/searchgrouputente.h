#ifndef SEARCHGROUPUTENTE_H
#define SEARCHGROUPUTENTE_H

#include <QString>

#include "query.h"

namespace SearchGroupUtente
{
    class ByUsername : public Query
    {
        private:
            QString username;

        public:
            ByUsername( const QString & );

            void compose( Frankenstein & ) const;
    };
}

#endif // SEARCHGROUPUTENTE_H
