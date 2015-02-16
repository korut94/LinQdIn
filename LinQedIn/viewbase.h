#ifndef VIEWBASE_H
#define VIEWBASE_H

#include <iostream>
#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "boardfriends.h"
#include "errorstate.h"
#include "id.h"
#include "info.h"
#include "levelaccess.h"
#include "lineeditvalidate.h"
#include "smartptr_utente.h"
#include "tableusers.h"
#include "top.h"
#include "viewexperience.h"

class ViewBase : public QWidget
{
    Q_OBJECT

    public slots:
        virtual void loadMainPage( const smartptr_utente & ) = 0;

    public:
        ViewBase( QWidget * = nullptr );
        ~ViewBase();
};

#endif // VIEWBASE_H
