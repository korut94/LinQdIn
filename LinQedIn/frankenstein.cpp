#include "frankenstein.h"

bool Frankenstein::matchExperiences( const QVector<Experience> & my,
                                     const QVector<Experience> & his ) const
{
    QVector<Experience>::const_iterator itrMy = my.begin();
    QVector<Experience>::const_iterator itrHis;

    bool isPresent = true;
    bool matchFound;

    while( itrMy != my.end() && isPresent )
    {
        matchFound = false;

        itrHis = his.begin();

        while( itrHis != his.end() && !matchFound )
        {
            matchFound = partialMatch( *itrMy, *itrHis );
            itrHis++;
        }

        isPresent = matchFound;
        itrMy++;
    }

    return isPresent;
}


bool Frankenstein::matchSkills( const QVector<Skill> & my,
                                const QVector<Skill> & his ) const
{
    QVector<Skill>::const_iterator itrMy = my.begin();
    QVector<Skill>::const_iterator itrHis;

    bool isPresent = true;
    bool matchFound;

    while( itrMy != my.end() && isPresent )
    {
        matchFound = false;

        itrHis = his.begin();

        while( itrHis != his.end() && !matchFound )
        {
            matchFound = partialMatch( *itrMy, *itrHis );
            itrHis++;
        }

        isPresent = matchFound;
        itrMy++;
    }

    return isPresent;
}


bool Frankenstein::partialMatch( const Experience & my,
                                 const Experience & his ) const
{
    if( !my.getCompany().isEmpty() &&
        my.getCompany() != his.getCompany() ) return false;

    if( !my.getDescription().isEmpty() &&
        my.getDescription() != his.getDescription() ) return false;

    if( !my.getPeriod().isEmpty() &&
        my.getPeriod() != his.getPeriod() ) return false;

    if( !my.getWork().isEmpty() &&
        my.getWork() != his.getWork() ) return false;

    return true;
}


bool Frankenstein::partialMatch( const Personal & my,
                                 const Personal & his ) const
{
    if( !my.getNome().isEmpty() &&
        my.getNome() != his.getNome() ) return false;

    if( !my.getCognome().isEmpty() &&
        my.getCognome() != his.getCognome() ) return false;

    if( !my.getDate().isNull() &&
        my.getDate() != his.getDate() ) return false;

    if( !my.getNumTelefono().isEmpty() &&
        my.getNumTelefono() != his.getNumTelefono() ) return false;

    return true;
}


bool Frankenstein::partialMatch( const Skill & my, const Skill & his ) const
{
    if( !my.getSkill().isEmpty() &&
        my.getSkill() != his.getSkill() ) return false;

    return true;
}


Frankenstein::Frankenstein() {}


Frankenstein::Frankenstein( const QString & username,
                            const Info & info )
                            : Entity( username, info ) {}

Frankenstein::Frankenstein( const Utente & utente )
                            : Entity( utente.getUsername(),
                                      utente.getInfo() ),
                              contatti( utente.getContatti() ) {}


bool Frankenstein::operator==( const Frankenstein & f ) const
{
    const Info & myInfo = getInfo();
    const Info & hisInfo = f.getInfo();

    return ( getUsername() == f.getUsername() &&

             partialMatch( myInfo.getPersonal(), hisInfo.getPersonal() ) &&

             matchExperiences( myInfo.getWorkExperiences(),
                               hisInfo.getWorkExperiences() ) &&

             matchSkills( myInfo.getSkills(), hisInfo.getSkills() ) &&

             matchExperiences( myInfo.getSchoolExperiences(),
                               hisInfo.getSchoolExperiences() ) );
}


bool Frankenstein::operator!=( const Frankenstein & f ) const
{
    return !( *this == f );
}
