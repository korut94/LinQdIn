#ifndef TABLEUSERS_H
#define TABLEUSERS_H

#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"

class TableUsers : public QWidget
{
    Q_OBJECT

    private:
        class UserItem : public QWidget
        {
            public:
                UserItem( const Info &, QWidget * = NULL );
                ~UserItem();
        };

    private:
        QLayout * listUsers;

    public:
        TableUsers( const QString & = QString(), QWidget * = NULL );

        void addItem( const Info & );

        ~TableUsers();
};

#endif // TABLEUSERS_H
