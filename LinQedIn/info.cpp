#include "info.h"

Info::Info( const Personal & data,
            const QVector<Skill> & sks,
            const QVector<Experience> & wrk,
            const QVector<Experience> & sch )
            : dataPersonal( data ),
              skills( sks ),
              workExperience( wrk ),
              schoolExperience( sch ){}

const QVector<Experience> & Info::getSchoolExperiences() const
{
    return schoolExperience;
}


const QVector<Experience> & Info::getWorkExperiences() const
{
    return workExperience;
}


const QVector<Skill> & Info::getSkills() const { return skills; }


Personal & Info::getPersonal() { return dataPersonal; }


const Personal & Info::getPersonal() const { return dataPersonal; }


void Info::addSchoolExperience( const Experience & e )
{
    schoolExperience.push_back( e );
}


void Info::addWorkExperience( const Experience & e )
{
    workExperience.push_back( e );
}


void Info::addSkill( const Skill & sk )
{
    skills.push_back( sk );
}


void Info::removeSchoolExperience( const Experience & e )
{
    int posExp = schoolExperience.indexOf( e );

    if( posExp != -1 ) schoolExperience.remove( posExp );
}


void Info::removeWorkExperience( const Experience & e )
{
    int posExp = workExperience.indexOf( e );

    if( posExp != -1 ) workExperience.remove( posExp );
}


void Info::removeSkill( const Skill & sk )
{
    int posSk = skills.indexOf( sk );

    if( posSk != -1 ) skills.remove( posSk );
}


void Info::setPersonal( const Personal & p ) { dataPersonal = p; }


void Info::setSchoolExperiences( const QVector<Experience> & sch )
{
    schoolExperience = sch;
}


void Info::setSkills( const QVector<Skill> & sks )
{
    skills = sks;
}


void Info::setWorkExperiences( const QVector<Experience> & wrk )
{
    workExperience = wrk;
}

