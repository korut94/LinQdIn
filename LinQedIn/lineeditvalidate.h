#ifndef LINEEDITVALIDATE_H
#define LINEEDITVALIDATE_H

#include <QLineEdit>
#include <QValidator>

/*
 * Non e' possibile usare l'ereditarieta multipla con QLineEdit e
 * QRegExpValidator perchè QObject non la supporta
 */
class LineEditValidate : public QLineEdit
{
    private:
        QRegExpValidator validator;

    public:
        LineEditValidate( const QRegExp &,
                          const QString & = QString(),
                          QWidget * = nullptr );

        QValidator::State check() const;
};

#endif // LINEEDITVALIDATE_H
