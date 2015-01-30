#ifndef MODULEEXPERIENCE_H
#define MODULEEXPERIENCE_H

#include <algorithm>
#include <iostream>
#include <QFormLayout>
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

                bool checkError() const;

                void reset();
        };

    private:
        QVector<ModuleQualifica*> listaQualifica;

    public:
        ModuleExperience( QWidget * = nullptr );
        ~ModuleExperience();

        bool checkError() const;

        QVector<Experience> getExperiences() const;

        void addExperience();
        void reset();
};

#endif // MODULEEXPERIENCE_H
