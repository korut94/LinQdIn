#ifndef MODULEEXPERIENCE_H
#define MODULEEXPERIENCE_H

#include <algorithm>
#include <iostream>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "experience.h"
#include "info.h"
#include "lineeditvalidate.h"
#include "modulequalifica.h"

class ModuleExperience : public QWidget
{
    Q_OBJECT

    private:
        QVector<ModuleQualifica*> listaQualifica;

    signals:
        void requestRemoveExperience( ModuleQualifica * ) const;

    public slots:
        void removeExperience( ModuleQualifica * );

    public:
        ModuleExperience( QWidget * = nullptr );
        ~ModuleExperience();

        bool complete() const;

        QVector<Experience> getExperiences() const;

        void addExperience( const Experience & = Experience() );
        void reset();
        void setContent( const QVector<Experience> & );
};

#endif // MODULEEXPERIENCE_H
