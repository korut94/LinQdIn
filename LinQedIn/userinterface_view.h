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
#include "smartptr_utente.h"
#include "tableusers.h"
#include "top.h"
#include "viewexperience.h"

class UserInterface_View : public QWidget
{
    Q_OBJECT

    private:
        QScrollArea * userUtility;

    signals:
        void requestModify();

    public slots:
        void loadMainPage( const smartptr_utente &, LevelAccess::Type );
        void setFrameUtility( QWidget * );

    public:
        UserInterface_View( const smartptr_utente &,
                            LevelAccess::Type = LevelAccess::I,
                            QWidget * = nullptr );
        ~UserInterface_View();
};

#endif // USERINTERFACE_VIEW_H
