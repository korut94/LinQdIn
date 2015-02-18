#ifndef MODULEEDUCATION_H
#define MODULEEDUCATION_H

#include <algorithm>
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "experience.h"
#include "info.h"
#include "lineeditvalidate.h"
#include "modulestudio.h"

class ModuleEducation : public QWidget
{
    Q_OBJECT

    private:
        QVector<ModuleStudio*> listaStudio;    

    signals:
        void requestRemoveStudio( ModuleStudio * ) const;

    public slots:
        void removeStudio( ModuleStudio * );

    public:
        ModuleEducation( QWidget * = nullptr );
        ~ModuleEducation();

        bool checkError() const;
        bool complete() const;

        QVector<Experience> getEducations() const;

        void addEducation( const Experience & = Experience() );
        void reset();
        void setContent( const QVector<Experience> & );
};

#endif // MODULEEDUCATION_H
