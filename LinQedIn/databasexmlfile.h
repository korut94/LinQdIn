#ifndef DATABASEFILE_H
#define DATABASEFILE_H

#include <QFile>
#include <QVector>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "database.h"
#include "smartptr_utente.h"

class DatabaseXmlFile : public Database, public QFile
{
    private:
        bool load;

    public:
        DatabaseXmlFile( const QString & );

        void loadDB();
        void saveDB();
};

#endif // DATABASEFILE_H
