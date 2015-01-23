#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "info.h"

class UserSearch : public QWidget
{
    QLineEdit * editName;

    signals:
        void sendUnknownUser( const Info & );

    private slots:
        void recapInfo();

    public:
        UserSearch( QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
