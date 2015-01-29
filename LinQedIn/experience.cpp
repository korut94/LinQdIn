#include "experience.h"

Experience::Experience( const QString & w,
                        const QString & c,
                        const QString & p,
                        const QString & d )
                        : work( w ),
                          company( c ),
                          period( p ),
                          description( d )
{
}


QString Experience::getCompany() const { return company; }


QString Experience::getDescripion() const { return description; }


QString Experience::getPeriod() const { return period; }


QString Experience::getWork() const { return work; }


void Experience::setCompany( const QString & comp ) { company = comp; }


void Experience::setDescripion( const QString & desc ) { description = desc; }


void Experience::setPeriod( const QString & per ) { period = per; }


void Experience::setWork( const QString & w ) { work = w; }



