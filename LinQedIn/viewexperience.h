#ifndef VIEWEXPERIENCE_H
#define VIEWEXPERIENCE_H

#include <iostream>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "boardfriends.h"
#include "info.h"
#include "levelaccess.h"
#include "tableusers.h"
#include "top.h"
#include "usereditpage.h"

class ViewExperience : public QWidget
{
    Q_OBJECT

    public:
        ViewExperience( const LevelAccess::Type &, QWidget * = nullptr );
        ~ViewExperience();
};

#endif // VIEWEXPERIENCE_H
