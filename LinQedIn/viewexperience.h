#ifndef VIEWEXPERIENCE_H
#define VIEWEXPERIENCE_H

#include <iostream>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "boardfriends.h"
#include "info.h"
#include "levelaccess.h"
#include "line.h"
#include "tableusers.h"
#include "top.h"
#include "usereditpage.h"

class ViewExperience : public QWidget
{
    Q_OBJECT

    public:
        ViewExperience( const Info &, QWidget * = nullptr );
        ~ViewExperience();
};

#endif // VIEWEXPERIENCE_H
