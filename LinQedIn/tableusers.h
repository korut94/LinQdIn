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
        QWidget * listUsers;

    public:
        TableUsers( QWidget * = NULL );
        ~TableUsers();
};

#endif // TABLEUSERS_H
