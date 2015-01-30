#ifndef MODULESKILLS_H
#define MODULESKILLS_H

#include <algorithm>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include "skill.h"

class ModuleSkills : public QWidget
{
    Q_OBJECT

    private:
        QVector<QLineEdit*> listaSkills;

    public:
        ModuleSkills( QWidget * = nullptr );
        ~ModuleSkills();

        QVector<Skill> getSkills() const;

        void addSkill();
        void reset();
};

#endif // MODULESKILLS_H
