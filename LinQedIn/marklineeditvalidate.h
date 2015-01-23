#ifndef MARKLINEEDITVALIDATE_H
#define MARKLINEEDITVALIDATE_H

#include <QLabel>
#include <QLineEdit>
#include <QValidator>

#include "checkgroupinput.h"

class MarkLineEditValidate : public QLabel,
                             public QLineEdit,
                             public QValidator
{
    public:
        MarkLineEditValidate( const CheckGroupInput::CheckInput & );

        MarkLineEditValidate( const QString &,
                              const CheckGroupInput::CheckInput & );

        MarkLineEditValidate( const QString &, const QString &,
                              const CheckGroupInput::CheckInput & );
};

#endif // MARKLINEEDITVALIDATE_H
