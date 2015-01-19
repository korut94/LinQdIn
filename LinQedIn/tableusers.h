#ifndef TABLEUSERS_H
#define TABLEUSERS_H

#include <QScrollArea>
#include <QWidget>

#include "info.h"
#include "useritem.h"

class TableUsers : public QWidget
{
    private:
        QWidget * users;

    public:
        TableUsers( QWidget * = NULL );
        ~TableUsers();
};

#endif // TABLEUSERS_H
