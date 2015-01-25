#ifndef USERINTERFACE_VIEW_H
#define USERINTERFACE_VIEW_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

enum LevelAccess
{
    I,
    Basic,
    Business,
    Executive,
    Master
};

class UserInterface_View : public QWidget
{
    private:
        LevelAccess level;

    public:
        UserInterface_View( LevelAccess = I, QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
