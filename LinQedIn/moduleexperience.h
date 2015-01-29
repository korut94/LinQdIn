#ifndef MODULEEXPERIENCE_H
#define MODULEEXPERIENCE_H

#include <algorithm>
#include <iostream>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "experience.h"
#include "lineeditvalidate.h"

class ModuleExperience : public QWidget
{
    Q_OBJECT

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

#endif // MODULEEXPERIENCE_H
