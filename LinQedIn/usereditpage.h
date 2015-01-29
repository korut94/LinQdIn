#ifndef USEREDITPAGE_H
#define USEREDITPAGE_H

#include <algorithm>
#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>
#include <QWidget>

#include "experience.h"
#include "info.h"
#include "line.h"
#include "lineeditvalidate.h"
#include "skill.h"

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

                        Experience getExperience() const;
                };

            private:
                QVector<ModuleQualifica*> listaQualifica;

            public:
                ModuleExperience( QWidget * = nullptr );

                QVector<Experience> getExperiences() const;

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
                QVector<QLineEdit*> listaSkills;

            public:
                ModuleSkills( QWidget * = nullptr );
                ~ModuleSkills();

                QVector<Skill> getSkills() const;
        };

    public:
        UserEditPage( QWidget * = nullptr );
        ~UserEditPage();
};

#endif // USEREDITPAGE_H
