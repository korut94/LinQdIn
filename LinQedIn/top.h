#ifndef TOP_H
#define TOP_H

#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "levelaccess.h"
#include "smartptr_utente.h"

class Top : public QWidget
{
    Q_OBJECT

    private:
        QPushButton * btnFriend;

    signals:
        void amici() const;
        void home() const;
        void nonAmici() const;

    private slots:
        void setAddFriend();
        void setRemoveFriend();

    public:
        Top( const smartptr_utente &, LevelAccess::Type, QWidget * = nullptr );
        ~Top();
};

#endif // TOP_H
