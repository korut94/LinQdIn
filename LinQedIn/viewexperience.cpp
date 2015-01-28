#include "viewexperience.h"

ViewExperience::ViewExperience( const LevelAccess::Type & level,
                                QWidget * parent )
                                : QWidget( parent )
{
    QLabel * lblExperience = new QLabel( tr( "Experience" ) );
    QLabel * lblSkills = new QLabel( tr( "Skills" ) );
    QLabel * lblEducation = new QLabel( tr( "Education" ) );

    QLabel * lineExp = new QLabel();
    lineExp->setFrameStyle( QFrame::HLine | QFrame::Plain );
    lineExp->setLineWidth( 1 );

    QLabel * lineSki = new QLabel();
    lineSki->setFrameStyle( QFrame::HLine | QFrame::Plain );
    lineSki->setLineWidth( 1 );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblExperience );
    //ciclo for
    layout->addWidget( lineExp );
    layout->addWidget( lblSkills );
    //ciclo for
    layout->addWidget( lineSki );
    layout->addWidget( lblEducation );
    //ciclo for

    setLayout( layout );
}


ViewExperience::~ViewExperience()
{

}
