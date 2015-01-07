#ifndef INFO_H
#define INFO_H

#include <QString>

class Info
{
    private:
        QString cognome;
        QString data; //class Data?
        QString nome;
        QString n_telefono; //class N_Telefono?

    public:
        Info();
        Info( const QString &, //nome
              const QString &, //cognome
              const QString &, //n_telefono
              const QString &  //data
            );

        QString getCognome() const;
        QString getData() const;
        QString getNome() const;
        QString getNumTelefono() const;

        void setCognome( const QString & );
        void setNome( const QString & );
        void setData( const QString & );
        void setNumTelefono( const QString & );
};

#endif // INFO_H
