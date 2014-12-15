#include "info.h"

Info::Info() //costruttori di default
{
}


Info::Info( const std::string & name,
            const std::string & surname,
            const std::string & number,
            const std::string & data )
            : nome( name ),
              cognome( surname ),
              n_telefono( number ),
              data( data )
{
}


std::string Info::getCognome() const
{
    return cognome;
}


std::string Info::getData() const
{
    return data;
}


std::string Info::getNome() const
{
    return nome;
}


std::string Info::getNumTelefono() const
{
    return n_telefono;
}


void Info::setCognome( const std::string & surname )
{
    cognome = surname;
}


void Info::setNome( const std::string & name )
{
    nome = name;
}


void Info::setData( const std::string & data )
{
    this->data = data;
}


void Info::setNumTelefono( const std::string & number )
{
    n_telefono = number;
}
