#ifndef MODULEID_H
#define MODULEID_H

#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
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
        LineEditValidate * editData_Day;
        LineEditValidate * editData_Month;
        LineEditValidate * editData_Year;

    public:
        ModuleID( QWidget * = nullptr );
        ~ModuleID();

        Personal getDataPersonal() const;
};

#endif // MODULEID_H
