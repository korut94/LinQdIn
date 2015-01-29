#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "line.h"
#include "usereditpage.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    signals:
        void searchUser( const Info & );

    public:
        UserSearch( QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
