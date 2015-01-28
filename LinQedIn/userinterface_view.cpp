#include "userinterface_view.h"

UserInterface_View::BoardFriends::BoardFriends( const LevelAccess & level,
                                                QWidget * parent )
                                                : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

    TableUsers * me = new TableUsers( tr( "Me" ) );
    me->setFixedHeight( 110 );
    me->addItem( Info( "Andrea", "Mantovani", "3406936174", "17/09/1994" ) );

    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    TableUsers * friends = new TableUsers( tr( "My cowork" ) );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( me );
    layout->addWidget( btnModify );
    layout->addWidget( friends );

    setLayout( layout );

    connect( btnModify, SIGNAL( clicked() ), this, SIGNAL( modify() ) );
}


UserInterface_View::BoardFriends::~BoardFriends()
{
}


UserInterface_View::ID::ID( const LevelAccess & level, QWidget * parent )
                            : QWidget( parent )
{
    QPixmap image( "../LinQedIn/User_150x114.png" );

    QLabel * lblImage = new QLabel();
    lblImage->setPixmap( image );

    QLabel * lblFullname = new QLabel( "Andrea Mantovani" );
    QLabel * lblTelephone = new QLabel( tr( "Telephone" ) + ':' );
    QLabel * valTelephone = new QLabel( "3406936174" );
    QLabel * lblData = new QLabel( tr( "Data" ) + ':' );
    QLabel * valData = new QLabel( "17/09/1994" );
    QLabel * lblJob = new QLabel( tr( "Job" ) + ':' );
    QLabel * valJob = new QLabel( "Student" );

    QFormLayout * layoutExtra = new QFormLayout;
    layoutExtra->setHorizontalSpacing( 25 );
    layoutExtra->addRow( lblTelephone, valTelephone );
    layoutExtra->addRow( lblData, valData );
    layoutExtra->addRow( lblJob, valJob );

    QVBoxLayout * layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget( lblFullname );
    layoutInfo->addLayout( layoutExtra );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setAlignment( Qt::AlignLeft );
    layout->addWidget( lblImage );
    layout->addLayout( layoutInfo );

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


UserInterface_View::ViewExperience::~ViewExperience()
{
}


UserInterface_View::Top::Top( const LevelAccess & level, QWidget * parent )
                              : QWidget( parent )

{
    QLabel * lblUser = new QLabel( tr( "Username" ) + ": korut94" );
    QLabel * lblAccount = new QLabel( tr( "Account" ) + ": Mega master" );

    QPushButton * btmFriend = new QPushButton( tr( "Add coworker" ) );
    btmFriend->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( lblUser );
    layout->addWidget( lblAccount );
    layout->addWidget( btmFriend );

    setLayout( layout );    
}


UserInterface_View::Top::~Top()
{
}


void UserInterface_View::deleteItems()
{
    QLayoutItem * child;

    while( ( child = layoutUserData->takeAt( 0 ) ) != nullptr ) delete child;
}


void UserInterface_View::loadUserData()
{
    if( layoutUserData->count() > 0 ) deleteItems();

    Top * top = new Top( level );
    ID * id = new ID( level );
    ViewExperience * exp = new ViewExperience( level );

    layoutUserData->setAlignment( Qt::AlignTop );
    layoutUserData->addWidget( top );
    layoutUserData->addWidget( id );
    layoutUserData->addWidget( exp );
}


void UserInterface_View::loadUserModify()
{
    if( layoutUserData->count() > 0 ) deleteItems();
    layoutUserData->addWidget( new UserEditPage() );
}


UserInterface_View::UserInterface_View( LevelAccess l, QWidget * parent )
                                        : level( l ),
                                          QWidget( parent )
{
    QScrollArea * area = new QScrollArea;

    layoutUserData = new QVBoxLayout;

    loadUserData();

    BoardFriends * boardFriends = new BoardFriends( level );

    QHBoxLayout * layoutInterface = new QHBoxLayout;
    layoutInterface->addLayout( layoutUserData );
    layoutInterface->addWidget( boardFriends );

    area->setLayout( layoutInterface );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( area );

    setLayout( layout );

    connect( boardFriends,
             SIGNAL( modify() ),
             this,
             SIGNAL( requestModify() ) );
}


UserInterface_View::~UserInterface_View()
{

}
