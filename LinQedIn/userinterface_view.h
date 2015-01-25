#ifndef USERINTERFACE_VIEW_H
#define USERINTERFACE_VIEW_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class UserInterface_View : public QWidget
{
    public:
        UserInterface_View( QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
