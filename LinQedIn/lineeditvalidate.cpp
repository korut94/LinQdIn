#include "lineeditvalidate.h"

LineEditValidate::LineEditValidate( const QRegExp & reg,
                                    const QString & text,
                                    QWidget * parent )
                                    : validator( reg ),
                                      QLineEdit( text, parent )

{
}


QValidator::State LineEditValidate::check() const
{
    QString input = QLineEdit::text();
    int length = input.length();

    return validator.validate( input, length );
}
