#ifndef INFO_H
#define INFO_H

#include <QDate>
#include <QString>
#include <QVector>

#include "experience.h"
#include "personal.h"
#include "skill.h"

class Info
{
    private:
        Personal dataPersonal;
        QVector<Skill> skills;
        QVector<Experience> experiences;

    public:
        Info( const Personal & = Personal(),
              const QVector<Skill> & = QVector<Skill>(),
              const QVector<Experience> & = QVector<Experience>() );

        QVector<Experience> getExperiences() const;
        QVector<Skill> getSkills() const;

        Personal & getPersonal();
        const Personal & getPersonal() const;

        void addExperience( const Experience & );
        void addSkill( const Skill & );
        void removeExperience( const Experience & );
        void removeSkill( const Skill & );
};

#endif // INFO_H
