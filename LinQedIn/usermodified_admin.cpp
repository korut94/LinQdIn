#include "usermodified_admin.h"

UserModified_Admin::UserModified_Admin( const smartptr_utente & user )
                                          : UserModified( user )
{
    loadModuleAccount( user );
}


UserModified_Admin::~UserModified_Admin()
{
}


void UserModified_Admin::checkToSanityInsert() const
{
    if( checkErrorForm() == ErrorState::None )
    {
        if( completeForm() ) emit modify( recapInfo(), getTypeUser() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}
