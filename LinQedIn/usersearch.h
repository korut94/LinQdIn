#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "database.h"
#include "errorstate.h"
#include "info.h"
#include "levelaccess.h"
#include "line.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    private:
        QLabel * lblError;
        QLineEdit * editName;
        QLineEdit * editSurname;
        Database * database;

    signals:
        void error( ErrorState::Type ) const;
        void search( const QVector<smartptr_utente> & ) const;

    public slots:
        void composeInfo() const;
        void reset();
        void manageLocalError( ErrorState::Type );

    public:
        UserSearch( Database *, QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
