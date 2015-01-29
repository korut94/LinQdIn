#ifndef SKILL_H
#define SKILL_H

#include <QString>

class Skill
{
    private:
        QString skill;

    public:
        Skill( const QString & = QString() );

        QString getSkill() const;

        void setSkill( const QString & );
};

#endif // SKILL_H
