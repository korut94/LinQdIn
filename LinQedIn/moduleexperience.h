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
#include "info.h"
#include "lineeditvalidate.h"

class ModuleExperience : public QWidget
{
    Q_OBJECT

    private:
        class ModuleQualifica : public QWidget
        {
            private:
                QLineEdit * editExp;
                QLineEdit * editCompany;
                QLineEdit * editDurata;
                QTextEdit * editDescrizione;

            public:
                ModuleQualifica( const Experience & = Experience(),
                                 QWidget * = nullptr );
                ~ModuleQualifica();

                Experience getExperience() const;

                bool complete() const;

                void reset();
        };

    private:
        QVector<ModuleQualifica*> listaQualifica;

    public:
        ModuleExperience( QWidget * = nullptr );
        ~ModuleExperience();

        bool complete() const;

        QVector<Experience> getExperiences() const;

        void addExperience( const Experience & = Experience() );
        void reset();
        void setContent( const QVector<Experience> & );
};

#endif // MODULEEXPERIENCE_H
