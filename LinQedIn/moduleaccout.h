#ifndef MODULEACCOUT_H
#define MODULEACCOUT_H

#include <QComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QWidget>

class ModuleAccout : public QWidget
{
    Q_OBJECT

    private:
        QComboBox * account;

    public:
        ModuleAccout( QWidget * = nullptr );
        ~ModuleAccout();

        void reset();
};

#endif // MODULEACCOUT_H
