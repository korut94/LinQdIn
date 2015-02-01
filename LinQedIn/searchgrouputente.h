#ifndef SEARCHGROUPUTENTE_H
#define SEARCHGROUPUTENTE_H

#include <QString>

#include "query.h"

namespace SearchGroupUtente
{
    class All : public Query
    {
        public:
            void compose( Frankenstein & ) const;
    };

    class ByUsername : public Query
    {
        private:
            QString username;

        public:
            ByUsername( const QString & );

            void compose( Frankenstein & ) const;
    };

    class ByNameAndSurname : public Query
    {
        private:
            QString name;
            QString surname;

        public:
            ByNameAndSurname( const QString &, const QString & );

            void compose( Frankenstein & ) const;
    };
}

#endif // SEARCHGROUPUTENTE_H
