#ifndef MODULESKILL_H
#define MODULESKILL_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "skill.h"

class ModuleSkill : public QWidget
{
    Q_OBJECT

    private:
        QLineEdit * editSkill;

    signals:
        void sendRemove( ModuleSkill * ) const;

    public slots:
        void remove();

    public:
        ModuleSkill( const Skill & = Skill(), QWidget * = nullptr );
        ~ModuleSkill();

        bool complete() const;

        Skill getSkill() const;

        void reset();
};

#endif // MODULESKILL_H
