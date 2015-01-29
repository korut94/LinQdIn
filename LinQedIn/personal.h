#ifndef PERSONAL_H
#define PERSONAL_H

#include <QDate>
#include <QString>

class Personal
{
    private:
        QString cognome;
        QDate data;
        QString nome;
        QString n_telefono; //class N_Telefono?

    public:
        Personal( const QString &, //nome
                  const QString &, //cognome
                  const QString &, //n_telefono
                  const QDate &  //data
                );

        QString getCognome() const;
        QDate getDate() const;
        QString getNome() const;
        QString getNumTelefono() const;

        void setCognome( const QString & );
        void setNome( const QString & );
        void setDate( const QDate & );
        void setNumTelefono( const QString & );
};

#endif // PERSONAL_H
