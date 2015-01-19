#ifndef USERITEM_H
#define USERITEM_H

#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidgetItem>
#include <QVBoxLayout>

#include "info.h"

class UserItem : public QWidget
{
    public:
        UserItem( const Info &, QWidget * = NULL );
        ~UserItem();
};

#endif // USERITEM_H
