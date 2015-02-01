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
        void error( ErrorState::Type ) const ;
        void errorMessage( const QString & ) const;
        void insert( const Info & ) const;

    public slots:
        LevelAccess::Type getAccoutTypeSet() const;

        void checkToSanityInsert() const;
        void manageLocalError( ErrorState::Type );

    public:
        UserInsert();
        ~UserInsert();

        QWidget * getView() const;
};

#endif // USERINSERT_H
