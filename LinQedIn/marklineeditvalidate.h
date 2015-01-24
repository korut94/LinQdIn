#ifndef MARKLINEEDITVALIDATE_H
#define MARKLINEEDITVALIDATE_H

#include <QLabel>

#include "lineeditvalidate.h"

class MarkLineEditValidate : public QWidget
{
    public:
        MarkLineEditValidate( const QRegExp &,
                              const QString & = QString(),
                              const QString & = QString(),
                              QWidget * = nullptr );

        ~MarkLineEditValidate();
};

#endif // MARKLINEEDITVALIDATE_H
