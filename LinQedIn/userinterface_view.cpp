#include "userinterface_view.h"

UserInterface_View::ID::ID( const LevelAccess & level, QWidget * parent )
                            : QWidget( parent )
{
    QPixmap image( "../LinQedIn/User_150x114.png" );

    QLabel * lblImage = new QLabel();
    lblImage->setPixmap( image );

    QLabel * lblFullname = new QLabel( "Andrea Mantovani" );
    QLabel * lblTelephone = new QLabel( tr( "Telephone" ) +
                                        ':' +
                                        "3406936174" );
    QLabel * lblData = new QLabel( tr( "Data" ) + ':' + "17/09/1994" );
    QLabel * lblJob = new QLabel( tr( "Job" ) + ':' + "Student" );


    QVBoxLayout * layoutDati = new QVBoxLayout;
    layoutDati->addWidget( lblFullname );
    layoutDati->addWidget( lblTelephone );
    layoutDati->addWidget( lblData );
    layoutDati->addWidget( lblJob );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( lblImage );
    layout->addLayout( layoutDati );

    setLayout( layout );
}


UserInterface_View::ID::~ID()
{
}


UserInterface_View::ViewExperience::ViewExperience( const LevelAccess & level,
                                                    QWidget * parent )
                                                    : QWidget( parent )
{
    QLabel * lblExperience = new QLabel( tr( "Experience" ) );
    QLabel * lblSkills = new QLabel( tr( "Skills" ) );
    QLabel * lblEducation = new QLabel( tr( "Education" ) );

    QLabel * line = new QLabel();
    line->setFrameStyle( QFrame::HLine | QFrame::Plain );
    line->setLineWidth( 1 );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblExperience );
    //ciclo for
    layout->addWidget( line );
    layout->addWidget( lblSkills );
    //ciclo for
    layout->addWidget( new QLabel( line ) );
    layout->addWidget( lblEducation );
    //ciclo for

    setLayout( layout );
}


UserInterface_View::ViewExperience::~ViewExperience()
{
}


UserInterface_View::Top::Top( const LevelAccess & level, QWidget * parent )
                              : QWidget( parent )

{
    QLabel * lblUser = new QLabel( tr( "Username" ) + ": korut94" );
    QLabel * lblAccount = new QLabel( tr( "Account" ) + ": Mega master" );

    QPushButton * btmFriend = new QPushButton( tr( "Add coworker" ) );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( lblUser );
    layout->addWidget( lblAccount );
    layout->addWidget( btmFriend );

    setLayout( layout );    
}


UserInterface_View::Top::~Top()
{
}


UserInterface_View::UserInterface_View( LevelAccess l, QWidget * parent )
                                        : level( l ),
                                          QWidget( parent )
{
    QScrollArea * area = new QScrollArea;

    Top * top = new Top( l );
    ID * id = new ID( l );
    ViewExperience * exp = new ViewExperience( l );

    QVBoxLayout * layoutUserData = new QVBoxLayout;
    layoutUserData->setAlignment( Qt::AlignTop );
    layoutUserData->addWidget( top );
    layoutUserData->addWidget( id );
    layoutUserData->addWidget( exp );

    QHBoxLayout * layoutInterface = new QHBoxLayout;
    layoutInterface->addLayout( layoutUserData );

    area->setLayout( layoutInterface );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( area );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{

}
