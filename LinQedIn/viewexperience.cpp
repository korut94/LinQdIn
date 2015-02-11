#include "viewexperience.h"

ViewExperience::ViewExperience( const Info & info,
                                QWidget * parent )
                                : QWidget( parent )
{
    QLabel * lblExperience = new QLabel( tr( "Experience" ) );
    QLabel * lblSkills = new QLabel( tr( "Skills" ) );
    QLabel * lblEducation = new QLabel( tr( "Education" ) );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblExperience );

    const QVector<Experience> & exp = info.getWorkExperiences();

    for( QVector<Experience>::const_iterator itr = exp.begin();
         itr != exp.end();
         itr++ )
    {
        layout->addWidget( new QLabel( itr->getWork() ) );
        layout->addWidget( new QLabel( itr->getCompany() ) );
        layout->addWidget( new QLabel( itr->getPeriod() ) );
        layout->addWidget( new QLabel( itr->getDescription() ) );
        layout->addWidget( new QWidget() );
    }

    layout->addWidget( new Line() );
    layout->addWidget( lblSkills );

    const QVector<Skill> & sks = info.getSkills();

    for( QVector<Skill>::const_iterator itr = sks.begin();
         itr != sks.end();
         itr++ )
    {
        layout->addWidget( new QLabel( itr->getSkill() ) );
        layout->addWidget( new QWidget() );
    }

    layout->addWidget( new Line() );
    layout->addWidget( lblEducation );

    const QVector<Experience> & edu = info.getSchoolExperiences();

    for( QVector<Experience>::const_iterator itr = edu.begin();
         itr != edu.end();
         itr++ )
    {
        layout->addWidget( new QLabel( itr->getWork() ) );
        layout->addWidget( new QLabel( itr->getCompany() ) );
        layout->addWidget( new QLabel( itr->getPeriod() ) );
        layout->addWidget( new QLabel( itr->getDescription() ) );
        layout->addWidget( new QWidget() );
    }

    setLayout( layout );
}


ViewExperience::~ViewExperience()
{

}
