#ifndef MODULEACCOUT_H
#define MODULEACCOUT_H

#include <iostream>
#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

#include "levelaccess.h"
#include "smartptr_utente.h"

class ModuleAccout : public QWidget
{
    Q_OBJECT

    private:
        QComboBox * account;

    public:
        ModuleAccout( const smartptr_utente & = nullptr, QWidget * = nullptr );
        ~ModuleAccout();

        LevelAccess::Type getTypeAccount() const;

        void reset();
};

#endif // MODULEACCOUT_H
