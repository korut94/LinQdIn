#include "personal.h"

Personal::Personal( const QString & name,
                    const QString & surname,
                    const QString & number,
                    const QDate & data )
                    : nome( name ),
                      cognome( surname ),
                      n_telefono( number ),
                      data( data )
{
}


QString Personal::getCognome() const
{
    return cognome;
}


QDate Personal::getDate() const
{
    return data;
}


QString Personal::getNome() const
{
    return nome;
}


QString Personal::getNumTelefono() const
{
    return n_telefono;
}


void Personal::setCognome( const QString & surname )
{
    cognome = surname;
}


void Personal::setNome( const QString & name )
{
    nome = name;
}


void Personal::setDate( const QDate & data )
{
    this->data = data;
}


void Personal::setNumTelefono( const QString & number )
{
    n_telefono = number;
}

