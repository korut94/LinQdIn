#ifndef BOARDFRIENDS_H
#define BOARDFRIENDS_H

#include <algorithm>
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "levelaccess.h"
#include "smartptr_utente.h"
#include "tableusers.h"
#include "usereditpage.h"

class BoardFriends : public QWidget
{
    Q_OBJECT

    private:
        TableUsers * friends;

    signals:
        void logout() const;
        void modify() const;
        void search() const;
        void select( const QString & ) const;

    public slots:
        void viewFriends( const Utente::Rete & );

    public:
        BoardFriends( const smartptr_utente &, QWidget * = nullptr );
        ~BoardFriends();
};

#endif // BOARDFRIENDS_H
