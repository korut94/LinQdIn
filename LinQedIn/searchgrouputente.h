#ifndef SEARCHGROUPUTENTE_H
#define SEARCHGROUPUTENTE_H

#include "smartptr_utente.h"
#include "utente.h"

namespace SearchGroupUtente
{
    class UgualeAdUtente
    {
        private:
            const Utente & user;

        public:
            UgualeAdUtente( const Utente & );

            bool operator()( const smartptr_utente & ) const;
    };
}

#endif // SEARCHGROUPUTENTE_H
