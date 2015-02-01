#ifndef MODULEID_H
#define MODULEID_H

#include <iostream>
#include <QComboBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListView>
#include <QVBoxLayout>

#include "lineeditvalidate.h"
#include "personal.h"

class ModuleID : public QWidget
{
    Q_OBJECT

    private:
        static const int startYear;

        LineEditValidate * editName;
        LineEditValidate * editSurname;
        LineEditValidate * editPrefixNumber;
        LineEditValidate * editNumber;
        QComboBox * editDate_Day;
        QComboBox * editDate_Month;
        QComboBox * editDate_Year;
        QLineEdit * editActualWork;

        static QStringList insertNumDay();
        static QStringList insertNameMonth();
        static QStringList insertNumYear();

    public:
        ModuleID( QWidget * = nullptr );
        ~ModuleID();

        bool checkError() const;
        bool complete() const;

        Personal getDatePersonal() const;

        void reset();
};

#endif // MODULEID_H
