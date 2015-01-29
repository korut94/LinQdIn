#ifndef MODULEID_H
#define MODULEID_H

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
        LineEditValidate * editUsername;
        LineEditValidate * editName;
        LineEditValidate * editSurname;
        LineEditValidate * editPrefixNumber;
        LineEditValidate * editNumber;
        QComboBox * editData_Day;
        QComboBox * editData_Month;
        QComboBox * editData_Year;

        static QStringList insertNumDay();
        static QStringList insertNameMonth();
        static QStringList insertNumYear();

    public:
        ModuleID( QWidget * = nullptr );
        ~ModuleID();

        Personal getDataPersonal() const;
};

#endif // MODULEID_H
