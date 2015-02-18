#include "usermodified_utente.h"

UserModified_Utente::UserModified_Utente( const smartptr_utente & user )
                                          : UserModified( user )
{
}


UserModified_Utente::~UserModified_Utente()
{
}


void UserModified_Utente::checkToSanityInsert() const
{
    if( checkErrorForm() == ErrorState::None )
    {
        if( completeForm() ) emit modify( recapInfo() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}
