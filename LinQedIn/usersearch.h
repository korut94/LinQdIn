#ifndef USERSEARCH_H
#define USERSEARCH_H

#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

#include "info.h"
#include "lineeditvalidate.h"

class UserSearch : public QWidget
{
    Q_OBJECT

    LineEditValidate * editName;
    LineEditValidate * editSurname;
    LineEditValidate * editPrefixNumber;
    LineEditValidate * editNumber;
    LineEditValidate * editData_Day;
    LineEditValidate * editData_Month;
    LineEditValidate * editData_Year;

    signals:
        void searchUser( const Info & );

    private slots:
        void recapInfo();

    public:
        UserSearch( QWidget * = nullptr );
        ~UserSearch();
};

#endif // USERSEARCH_H
