#ifndef LINEEDITVALIDATE_H
#define LINEEDITVALIDATE_H

#include <QLineEdit>
#include <QValidator>

class LineEditValidate : public QLineEdit,
                         public QRegExpValidator
{
    public:
        LineEditValidate( const QRegExp &,
                          const QString & = QString(),
                          QWidget * = nullptr );

        State check() const;
};

#endif // LINEEDITVALIDATE_H
