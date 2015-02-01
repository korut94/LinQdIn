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
        QVector<Experience> schoolExperience;
        QVector<Experience> workExperience;

    public:
        Info( const Personal & = Personal(),
              const QVector<Skill> & = QVector<Skill>(),
              const QVector<Experience> & = QVector<Experience>(),
              const QVector<Experience> & = QVector<Experience>() );

        const QVector<Experience> & getSchoolExperiences() const;
        const QVector<Experience> & getWorkExperiences() const;
        const QVector<Skill> & getSkills() const;

        Personal & getPersonal();
        const Personal & getPersonal() const;

        void addSchoolExperience( const Experience & );
        void addWorkExperience( const Experience & );
        void addSkill( const Skill & );
        void removeSchoolExperience( const Experience & );
        void removeWorkExperience( const Experience & );
        void removeSkill( const Skill & );
        void setPersonal( const Personal & );
        void setSchoolExperiences( const QVector<Experience> & );
        void setSkills( const QVector<Skill> & );
        void setWorkExperiences( const QVector<Experience> & );
};

#endif // INFO_H
