#ifndef MODULEQUALIFICA_H
#define MODULEQUALIFICA_H

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

class ModuleQualifica : public QWidget
{
    Q_OBJECT

    private:
        QLineEdit * editExp;
        QLineEdit * editCompany;
        QLineEdit * editDurata;
        QTextEdit * editDescrizione;

    signals:
        void sendRemove( ModuleQualifica * ) const;

    private slots:
        void remove();

    public:
        ModuleQualifica( const Experience & = Experience(),
                         QWidget * = nullptr );
        ~ModuleQualifica();

        Experience getExperience() const;

        bool complete() const;

        void reset();
};

#endif // MODULEQUALIFICA_H
