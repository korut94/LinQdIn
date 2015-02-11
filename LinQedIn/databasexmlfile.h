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
    public:
        DatabaseXmlFile( const QString & );
		~DatabaseXmlFile();

        void load();
        void save();
};

#endif // DATABASEXMLFILE_H
