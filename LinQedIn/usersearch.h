#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "info.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    QLineEdit * editName;

    signals:
        void searchUser( const Info & );

    public slots:
        void recapInfo();

    public:
        UserSearch( QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
