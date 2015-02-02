#ifndef USERITEM_H
#define USERITEM_H

#include <iostream>
#include <QAbstractButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "smartptr_utente.h"

class UserItem : public QWidget
{
    Q_OBJECT

    private:
        QString username;

    signals:
        void selectThis( const QString & ) const;

    protected:
       void mousePressEvent( QMouseEvent * );

    public:
        UserItem( const smartptr_utente &, QWidget * = NULL );
        ~UserItem();
};

#endif // USERITEM_H
