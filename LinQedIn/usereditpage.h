#ifndef USEREDITPAGE_H
#define USEREDITPAGE_H

#include <iostream>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>

#include "info.h"
#include "line.h"
#include "moduleexperience.h"
#include "moduleid.h"
#include "moduleskills.h"

class UserEditPage : public QWidget
{
    Q_OBJECT

    private:
        ModuleExperience * exp;
        ModuleID * id;
        ModuleSkills * sks;

    public slots:
        Info recapInfo() const;

    public:
        UserEditPage( QWidget * = nullptr );
        ~UserEditPage();
};

#endif // USEREDITPAGE_H
