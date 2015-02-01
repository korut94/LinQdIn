#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "errorstate.h"
#include "info.h"
#include "levelaccess.h"
#include "line.h"
#include "usereditpage.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    private:
        LevelAccess::Type level;
        UserEditPage * editPage;

    signals:
        void error( ErrorState::Type ) const;
        void errorMessage( const QString & ) const;
        void search( const Info & ) const;

    public slots:
        void checkToSanityInsert() const;
        void manageLocalError( ErrorState::Type );

    public:
        UserSearch( LevelAccess::Type, QWidget * = nullptr );
        ~UserSearch();

        QWidget * getView() const;
};

#endif // USERSEARCH_H
