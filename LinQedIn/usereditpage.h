#ifndef USEREDITPAGE_H
#define USEREDITPAGE_H

#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>
#include <QWidget>

#include "info.h"
#include "lineeditvalidate.h"

class UserEditPage : public QWidget
{
    Q_OBJECT

    private:
        class ModuleExperience : public QWidget
        {
            private:
                class ModuleQualifica : public QWidget
                {
                    private:
                        LineEditValidate * editExp;
                        QLineEdit * editCompany;
                        QLineEdit * editDurata;
                        QTextEdit * editDescrizione;

                    public:
                        ModuleQualifica( QWidget * = nullptr );
                        ~ModuleQualifica();
                };

            private:
                QVBoxLayout * layout;

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

        class ModuleSkills : public QWidget
        {
            private:
                QVBoxLayout * layout;

            public:
                ModuleSkills( QWidget * = nullptr );
                ~ModuleSkills();
        };

    public:
        UserEditPage( QWidget * = nullptr );
        ~UserEditPage();
};

#endif // USEREDITPAGE_H
