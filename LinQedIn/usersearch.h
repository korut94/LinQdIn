#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

#include "info.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    QLineEdit * editName;

    signals:
        void searchUser( const Info & );

    private slots:
        void recapInfo();

    public:
        UserSearch( QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
