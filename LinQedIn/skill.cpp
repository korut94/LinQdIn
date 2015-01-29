#include "skill.h"

Skill::Skill( const QString & sk ) : skill( sk ) {}


QString Skill::getSkill() const { return skill; }


void Skill::setSkill( const QString & sk ) { skill = sk; }
