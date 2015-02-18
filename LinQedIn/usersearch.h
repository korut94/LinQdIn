#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "database.h"
#include "errorstate.h"
#include "info.h"
#include "levelaccess.h"
#include "line.h"
#include "usereditpage.h"

class UserSearch : public UserEditPage
{
    Q_OBJECT

    private:
        Database * database;

    signals:
        void search( const QVector<smartptr_utente> & ) const;

    public slots:
        void checkToSanityInsert() const;

    public:
        UserSearch( Database *, QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
