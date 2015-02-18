#ifndef DATABASEFILE_H
#define DATABASEFILE_H

#include <QFile>

#include "databaseio.h"

class DatabaseFile : public DatabaseIO, public QFile
{
    public:
        DatabaseFile( const QString & );
        ~DatabaseFile();
};

#endif // DATABASEFILE_H
