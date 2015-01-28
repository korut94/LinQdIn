#include "viewexperience.h"

ViewExperience::ViewExperience( const LevelAccess::Type & level,
                                QWidget * parent )
                                : QWidget( parent )
{
    QLabel * lblExperience = new QLabel( tr( "Experience" ) );
    QLabel * lblSkills = new QLabel( tr( "Skills" ) );
    QLabel * lblEducation = new QLabel( tr( "Education" ) );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblExperience );
    //ciclo for
    layout->addWidget( new Line() );
    layout->addWidget( lblSkills );
    //ciclo for
    layout->addWidget( new Line() );
    layout->addWidget( lblEducation );
    //ciclo for

    setLayout( layout );
}


ViewExperience::~ViewExperience()
{

}
