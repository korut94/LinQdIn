#include "info.h"

Info::Info( const Personal & data,
            const QVector<Skill> & sks,
            const QVector<Experience> & exp )
            : dataPersonal( data ), skills( sks ), experiences( exp ) {}


QVector<Experience> Info::getExperiences() const { return experiences; }


QVector<Skill> Info::getSkills() const { return skills; }


Personal & Info::getPersonal() { return dataPersonal; }


const Personal & Info::getPersonal() const { return dataPersonal; }


void Info::addExperience( const Experience & e )
{
    experiences.push_back( e );
}


void Info::addSkill( const Skill & sk )
{
    skills.push_back( sk );
}


void Info::removeExperience( const Experience & e )
{
    int posExp = experiences.indexOf( e );

    if( posExp != -1 ) experiences.remove( posExp );
}


void Info::removeSkill( const Skill & sk )
{
    int posSk = skills.indexOf( sk );

    if( posSk != -1 ) skills.remove( posSk );
}
