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
