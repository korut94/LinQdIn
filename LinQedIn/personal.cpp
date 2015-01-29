#include "personal.h"

Personal::Personal( const QString & name,
                    const QString & surname,
                    const QString & number,
                    const QString & data )
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


QString Personal::getData() const
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


void Personal::setData( const QString & data )
{
    this->data = data;
}


void Personal::setNumTelefono( const QString & number )
{
    n_telefono = number;
}

