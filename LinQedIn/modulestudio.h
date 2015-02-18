#ifndef MODULESTUDIO_H
#define MODULESTUDIO_H

#include <algorithm>
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "experience.h"
#include "info.h"
#include "lineeditvalidate.h"

class ModuleStudio : public QWidget
{
    Q_OBJECT

    private:
        LineEditValidate * editSchool;
        QLineEdit * editTitle;
        QLineEdit * editDurata;
        QTextEdit * editDescrizione;

    signals:
        void sendRemove( ModuleStudio * ) const;

    public slots:
        void remove();

    public:
        ModuleStudio( const Experience & = Experience(),
                      QWidget * = nullptr );
        ~ModuleStudio();

        bool checkError() const;
        bool complete() const;

        Experience getEducation() const;

        void reset();
};

#endif // MODULESTUDIO_H
