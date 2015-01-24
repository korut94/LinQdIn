#ifndef LINEEDITVALIDATE_H
#define LINEEDITVALIDATE_H

#include <QLineEdit>

#include "checkgroupinput.h"

class LineEditValidate : virtual public QLineEdit,
                         virtual public QRegExpValidator
{
    public:
        LineEditValidate( const QRegExp &,
                          const QString & = QString(),
                          QWidget * = nullptr );

        State check() const;
};

#endif // LINEEDITVALIDATE_H
