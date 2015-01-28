#ifndef USERINTERFACE_VIEW_H
#define USERINTERFACE_VIEW_H

#include <iostream>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "tableusers.h"
#include "usereditpage.h"

enum LevelAccess
{
    I,
    Basic,
    Business,
    Executive,
    Modify,
    Master
};

class UserInterface_View : public QWidget
{
    private:
        class BoardFriends : public QWidget
        {
            signals:
                void modify();

            public:
                BoardFriends( const LevelAccess &, QWidget * = nullptr );
                ~BoardFriends();
        };

        class ID : public QWidget
        {
            public:
                ID( const LevelAccess &, QWidget * = nullptr );
                ~ID();
        };

        class ViewExperience : public QWidget
        {
            public:
                ViewExperience( const LevelAccess &, QWidget * = nullptr );
                ~ViewExperience();
        };

        class Top : public QWidget
        {
            public:
                Top( const LevelAccess &, QWidget * = nullptr );
                ~Top();
        };

    private:
        LevelAccess level;

        QLayout * layoutUserData;

        void deleteItems();

    signals:
        void requestModify();

    public slots:
        void loadUserData();
        void loadUserModify();

    public:
        UserInterface_View( LevelAccess = I, QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
