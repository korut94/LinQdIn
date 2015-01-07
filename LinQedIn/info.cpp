#include "info.h"

Info::Info() //costruttori di default
{
}


Info::Info( const QString & name,
            const QString & surname,
            const QString & number,
            const QString & data )
            : nome( name ),
              cognome( surname ),
              n_telefono( number ),
              data( data )
{
}


QString Info::getCognome() const
{
    return cognome;
}


QString Info::getData() const
{
    return data;
}


QString Info::getNome() const
{
    return nome;
}


QString Info::getNumTelefono() const
{
    return n_telefono;
}


void Info::setCognome( const QString & surname )
{
    cognome = surname;
}


void Info::setNome( const QString & name )
{
    nome = name;
}


void Info::setData( const QString & data )
{
    this->data = data;
}


void Info::setNumTelefono( const QString & number )
{
    n_telefono = number;
}
