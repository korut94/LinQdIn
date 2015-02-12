#ifndef DATABASEXMLFILE_H
#define DATABASEXMLFILE_H

#include <iostream>
#include <QFile>
#include <QVector>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "databaseio.h"

class DatabaseXmlFile : public DatabaseIO, public QFile
{
    private:
        QVector<smartptr_utente>::iterator
        foundUserBuffer( QVector<smartptr_utente> &, const QString & );

    public:
        DatabaseXmlFile( const QString & );
		~DatabaseXmlFile();

        void load();
        void save();
};

#endif // DATABASEXMLFILE_H
