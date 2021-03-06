#ifndef DATABASEXMLFILE_H
#define DATABASEXMLFILE_H

#include <iostream>
#include <QFile>
#include <QVector>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "databasefile.h"

class DatabaseXmlFile : public DatabaseFile
{
    private:
        QVector<smartptr_utente>::iterator
        foundUserBuffer( QVector<smartptr_utente> &, const QString & );

		QXmlStreamReader reader;
		QXmlStreamWriter writer;

    public:
        DatabaseXmlFile( const QString & );
		~DatabaseXmlFile();

        bool load();
        bool save();

		QString error() const;
};

#endif // DATABASEXMLFILE_H
