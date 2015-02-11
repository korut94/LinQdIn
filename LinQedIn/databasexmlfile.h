#ifndef DATABASEXMLFILE_H
#define DATABASEXMLFILE_H

#include <QFile>
#include <QVector>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "databaseio.h"
#include "smartptr_utente.h"

class DatabaseXmlFile : public DatabaseIO, public QFile
{
    public:
        DatabaseXmlFile( const QString & );
		~DatabaseXmlFile();

        void load();
        void save();
};

#endif // DATABASEXMLFILE_H
