#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "errorstate.h"
#include "info.h"
#include "levelaccess.h"
#include "line.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    private:
        QLineEdit * editName;
        QLineEdit * editSurname;

    signals:
        void search( const Info & ) const;

    public slots:
        void composeInfo() const;
        void reset();

    public:
        UserSearch( QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
