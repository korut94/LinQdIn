#ifndef USERMODIFIED_H
#define USERMODIFIED_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "line.h"
#include "usereditpage.h"

class UserModified : public QWidget
{
    Q_OBJECT

    public:
        UserModified( QWidget * = nullptr );
        ~UserModified();
};

#endif // USERMODIFIED_H
