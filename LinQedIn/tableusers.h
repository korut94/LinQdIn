#ifndef TABLEUSERS_H
#define TABLEUSERS_H

#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

#include "info.h"
#include "useritem.h"

class TableUsers : public QWidget
{
    Q_OBJECT

    private:
        QWidget * listUsers;

    private slots:
        void addUser();

    public:
        TableUsers( QWidget * = NULL );
        ~TableUsers();
};

#endif // TABLEUSERS_H
