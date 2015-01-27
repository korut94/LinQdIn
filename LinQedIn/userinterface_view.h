#ifndef USERINTERFACE_VIEW_H
#define USERINTERFACE_VIEW_H

#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

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
        class ViewExperience : public QWidget
        {
            private:

            public:

        };

        class ID: public QWidget
        {
            private:
                QStackedWidget * name;
                QStackedWidget * surname;
                QStackedWidget * telephone;
                QStackedWidget * data;
                QStackedWidget * job;

            public:
                ID( LevelAccess, QWidget * = nullptr );
                ~ID();
        };

        class Top : public QWidget
        {
            private:
                QStackedWidget * username;
                QStackedWidget * typeAccount;

            public:
                Top( LevelAccess, QWidget * = nullptr );
                ~Top();
        };

    private:
        LevelAccess level;

    public:
        UserInterface_View( LevelAccess = I, QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
