#ifndef MODULEACCOUT_H
#define MODULEACCOUT_H

#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "levelaccess.h"

class ModuleAccout : public QWidget
{
    Q_OBJECT

    private:
        QComboBox * account;

    public:
        ModuleAccout( QWidget * = nullptr );
        ~ModuleAccout();

        LevelAccess::Type getTypeAccount() const;

        void reset();
};

#endif // MODULEACCOUT_H
