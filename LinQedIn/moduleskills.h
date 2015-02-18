#ifndef MODULESKILLS_H
#define MODULESKILLS_H

#include <algorithm>
#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include "info.h"
#include "moduleskill.h"
#include "skill.h"

class ModuleSkills : public QWidget
{
    Q_OBJECT

    private:
        QVector<ModuleSkill*> listaSkills;

    signals:
        void requestRemoveSkill( ModuleSkill * ) const;

    public slots:
        void removeSkill( ModuleSkill * );

    public:
        ModuleSkills( QWidget * = nullptr );
        ~ModuleSkills();

        QVector<Skill> getSkills() const;

        bool complete() const;

        void addSkill( const Skill & = Skill() );
        void reset();
        void setContent( const QVector<Skill> & );
};

#endif // MODULESKILLS_H
