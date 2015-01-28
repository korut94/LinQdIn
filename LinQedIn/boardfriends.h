#ifndef BOARDFRIENDS_H
#define BOARDFRIENDS_H

#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "levelaccess.h"
#include "tableusers.h"
#include "usereditpage.h"

class BoardFriends : public QWidget
{
    Q_OBJECT

    signals:
        void modify();

    public:
        BoardFriends( const LevelAccess::Type &, QWidget * = nullptr );
        ~BoardFriends();
};

#endif // BOARDFRIENDS_H
