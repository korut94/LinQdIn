#ifndef ADMININTERFACE_VIEW_H
#define ADMININTERFACE_VIEW_H

#include <iostream>
#include <QPushButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QWidget>

#include "labeltools.h"
#include "tableusers.h"
#include "usersearch.h"

class AdminInterface_View : public QWidget
{
    Q_OBJECT

    private:
        QScrollArea * utility;

    signals:
        void requestToSearchUsers() const;
        void requestToAddUser() const;
        void requestToViewUser( const QString & ) const;
        void requestToViewUsers() const;
        void requestToRemoveUser() const;
        void requestToSaveDB() const;
        void requestToLoadDB() const;
        void updateTable( const QVector<smartptr_utente> & ) const;

    public slots:
        void setFrameUtility( QWidget * );

    public:
        AdminInterface_View( QWidget * = nullptr );
        ~AdminInterface_View();
};

#endif // ADMININTERFACE_VIEW_H
