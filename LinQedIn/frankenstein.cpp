#include "frankenstein.h"

Frankenstein::Frankenstein() {}


Frankenstein::Frankenstein( const QString & username,
                            const QString & password,
                            const Info & info )
                            : Entity( username, password, info ) {}

Frankenstein::Frankenstein( const Utente & utente )
                            : Entity( utente.getUsername(),
                                      utente.getPassword(),
                                      utente.getInfo() ),
                              contatti( utente.getContatti() ) {}


bool Frankenstein::operator==( const Frankenstein & f ) const
{
    bool equal = true;

    QString myUser = getUsername();
    QString myPass = getPassword();
    const Info & myInfo = getInfo();

    const Info & infoF = f.getInfo();

    //Dipendente dai campi Info, bruttino
    equal = equal && ( myUser.isEmpty() || myUser == f.getUsername() );

    equal = equal && ( myPass.isEmpty() || myPass == f.getPassword() );

    equal = equal && ( myInfo.getNome().isEmpty()
                       || myInfo.getNome() == infoF.getNome() );

    equal = equal && ( myInfo.getCognome().isEmpty()
                       || myInfo.getCognome() == infoF.getCognome() );

    equal = equal && ( myInfo.getData().isEmpty()
                       || myInfo.getData() == infoF.getData() );

    equal = equal && ( myInfo.getNumTelefono().isEmpty()
                       || myInfo.getNumTelefono() == infoF.getNumTelefono() );

    return equal;
}


bool Frankenstein::operator!=( const Frankenstein & f ) const
{
    return !( *this == f );
}
