#include "skill.h"

Skill::Skill( const QString & sk ) : skill( sk ) {}


bool Skill::operator==( const Skill & sk ) const
{
    return skill == sk.skill;
}


bool Skill::operator!=( const Skill & sk ) const
{
    return !( *this == sk );
}


QString Skill::getSkill() const { return skill; }


void Skill::setSkill( const QString & sk ) { skill = sk; }
