#include "viewexperience.h"

ViewExperience::ViewExperience( const Info & info,
                                QWidget * parent )
                                : QWidget( parent )
{
    QLabel * lblExperience = new QLabel( tr( "Experience" ) );
    lblExperience->setStyleSheet(
                "QLabel{ font-weight: bold; font-size: 14pt; }" );
    QLabel * lblSkills = new QLabel( tr( "Skills" ) );
    lblSkills->setStyleSheet(
                "QLabel{ font-weight: bold; font-size: 14pt; }" );
    QLabel * lblEducation = new QLabel( tr( "Education" ) );
    lblEducation->setStyleSheet(
                "QLabel{ font-weight: bold; font-size: 14pt; }" );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblExperience );

    const QVector<Experience> & exp = info.getWorkExperiences();

    for( QVector<Experience>::const_iterator itr = exp.begin();
         itr != exp.end();
         itr++ )
    {
        QLabel * work = new QLabel( itr->getWork() );
        work->setStyleSheet( "QLabel{ font-weight: bold; }" );

        layout->addWidget( work );
        layout->addWidget( new QLabel( itr->getCompany() ) );

        QLabel * period = new QLabel( itr->getPeriod() );
        period->setStyleSheet( "QLabel{ font-size: 10pt; }" );

        layout->addWidget( period );
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
        QLabel * work = new QLabel( itr->getWork() );
        work->setStyleSheet( "QLabel{ font-weight: bold; }" );

        layout->addWidget( work );
        layout->addWidget( new QLabel( itr->getCompany() ) );

        QLabel * period = new QLabel( itr->getPeriod() );
        period->setStyleSheet( "QLabel{ font-size: 10pt; }" );

        layout->addWidget( period );
        layout->addWidget( new QLabel( itr->getDescription() ) );
        layout->addWidget( new QWidget() );
    }

    setLayout( layout );
}


ViewExperience::~ViewExperience()
{

}
