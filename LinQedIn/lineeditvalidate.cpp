#include "lineeditvalidate.h"

LineEditValidate::LineEditValidate( const QRegExp & reg,
                                    const QString & text,
                                    QWidget * parent )
                                    : QRegExpValidator( reg ),
                                      QLineEdit( text, parent )

{
}


State LineEditValidate::check() const
{
    QString input = QLineEdit::text();

    return QRegExpValidator::validate( input, input.length()  );
}
