#ifndef USEREDITPAGE_H
#define USEREDITPAGE_H

#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

#include "info.h"
#include "lineeditvalidate.h"

class UserEditPage : public QWidget
{
    Q_OBJECT

    private:
        class ModuleExperience : public QWidget
        {
            public:
                ModuleExperience( QWidget * = nullptr );
                ~ModuleExperience();
        };

        class ModuleID : public QWidget
        {
            private:
                LineEditValidate * editUsername;
                LineEditValidate * editName;
                LineEditValidate * editSurname;
                LineEditValidate * editPrefixNumber;
                LineEditValidate * editNumber;
                LineEditValidate * editData_Day;
                LineEditValidate * editData_Month;
                LineEditValidate * editData_Year;

            public:
                ModuleID( QWidget * = nullptr );
                ~ModuleID();
        };

    private:


    public:
        UserEditPage( QWidget * = nullptr );
        ~UserEditPage();
};

#endif // USEREDITPAGE_H
