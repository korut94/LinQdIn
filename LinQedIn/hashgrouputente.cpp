#include "hashgrouputente.h"

int HashGroupUtente::AlfabeticoCreUpCase::operator()
                                          ( const Utente & user ) const
{
    QString name = user.getInfo().getNome();
    return name[0].toLatin1() - static_cast<int>( 'A' );
}


int HashGroupUtente::AlfabeticoDecUpCase::operator()
                                          ( const Utente & user ) const
{
    QString name = user.getInfo().getNome();
    return static_cast<int>( 'Z' ) - name[0].toLatin1();
}
