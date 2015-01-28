#ifndef USERINTERFACE_VIEW_H
#define USERINTERFACE_VIEW_H

#include <iostream>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "boardfriends.h"
#include "id.h"
#include "info.h"
#include "levelaccess.h"
#include "tableusers.h"
#include "top.h"
#include "viewexperience.h"

class UserInterface_View : public QWidget
{
    Q_OBJECT

    private:
        LevelAccess::Type level;

        QScrollArea * userUtility;

    signals:
        void requestModify();

    public slots:
        void loadMainPage();
        void setFrameUtility( QWidget * );

    public:
        UserInterface_View( LevelAccess::Type = LevelAccess::I,
                            QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
