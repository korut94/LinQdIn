#ifndef USERINSERT_H
#define USERINSERT_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "errorstate.h"
#include "line.h"
#include "usereditpage.h"

class UserInsert : public UserEditPage
{
    Q_OBJECT

    signals:
        void error( ErrorState::Type ) const ;
        void insert( const Info &, LevelAccess::Type ) const;

    public slots:
        void checkToSanityInsert() const;

    public:
        UserInsert();
        ~UserInsert();
};

#endif // USERINSERT_H
