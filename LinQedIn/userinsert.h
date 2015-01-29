#ifndef USERINSERT_H
#define USERINSERT_H

#include <iostream>
#include <QPushButton>
#include <QWidget>

#include "info.h"
#include "line.h"
#include "usereditpage.h"

class UserInsert : public QWidget
{
    Q_OBJECT

    public:
        UserInsert();
        ~UserInsert();
};

#endif // USERINSERT_H
