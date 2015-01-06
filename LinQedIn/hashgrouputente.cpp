#include "hashgrouputente.h"

int HashGroupUtente::AlfabeticoCreUpCase::operator()
                                          ( const QString & name ) const
{
    return name[0].toLatin1() - static_cast<int>( 'A' );
}


int HashGroupUtente::AlfabeticoDecUpCase::operator()
                                          ( const QString & name ) const
{
    return static_cast<int>( 'Z' ) - name[0].toLatin1();
}
