#ifndef TABLEUSERS_H
#define TABLEUSERS_H

#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "useritem.h"

class TableUsers : public QWidget
{
    Q_OBJECT

    private:
        QScrollArea * areaTable;

    public slots:
        void setItems( const QVector<Info> & );

    public:
        TableUsers( const QString & = QString(), QWidget * = NULL );
        ~TableUsers();
};

#endif // TABLEUSERS_H
