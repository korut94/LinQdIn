#ifndef USERMODIFIED_H
#define USERMODIFIED_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "line.h"
#include "smartptr_utente.h"
#include "usereditpage.h"

class UserModified : public QWidget
{
    Q_OBJECT

    private:
        UserEditPage * editPage;

    signals:
        void error( ErrorState::Type ) const;
        void errorMessage( const QString & ) const;
        void modify( const Info &, LevelAccess::Type ) const;

    public slots:
        void checkToSanityInsert() const;
        void manageLocalError( ErrorState::Type );

    public:
        UserModified( const smartptr_utente &,
                      LevelAccess::Type,
                      QWidget * = nullptr );
        ~UserModified();
};

#endif // USERMODIFIED_H