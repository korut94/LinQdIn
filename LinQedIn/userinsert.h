#ifndef USERINSERT_H
#define USERINSERT_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "errorstate.h"
#include "line.h"
#include "usereditpage.h"

class UserInsert : public QObject
{
    Q_OBJECT

    private:
        UserEditPage * editPage;

    signals:
        void error( ErrorState::Type );
        void errorMessage( const QString & );
        void insert( const Info & );

    public slots:
        void checkToSanityInsert();
        void manageLocalError( ErrorState::Type );
        void setErrorMessage( const QString & );

    public:
        UserInsert();
        ~UserInsert();

        QWidget * getView() const;
};

#endif // USERINSERT_H
