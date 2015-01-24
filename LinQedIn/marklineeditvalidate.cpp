#include "marklineeditvalidate.h"

MarkLineEditValidate::MarkLineEditValidate( const QRegExp & reg,
                                            const QString & textLabel,
                                            const QString & textLineEdit,
                                            QWidget * parent )
                                            : QWidget( parent )
{
    LineEditValidate * edit = new LineEditValidate( reg, textLineEdit );
    QLabel * label = new QLabel( textLabel );
}
