#include "userinterface_view.h"

UserInterface_View::ID::ID( LevelAccess level, QWidget * parent )
                            : QWidget( parent ),
                              name( new QStackedWidget ),
                              surname( new QStackedWidget ),
                              telephone( new QStackedWidget ),
                              data( new QStackedWidget ),
                              job( new QStackedWidget )
{
    QPixmap image( "../LinQedIn/User_150x114.png" );

    QLabel * lblImage = new QLabel();
    lblImage->setPixmap( image );

    name->addWidget( new QLabel( "Andrea" ) );
    name->addWidget( new QLineEdit( "Andrea" ) );
    surname->addWidget( new QLabel( "Mantovani" ) );
    surname->addWidget( new QLineEdit( "Mantovani" ) );
    telephone->addWidget( new QLabel( "3406936174" ) );
    telephone->addWidget( new QLineEdit( "3406936174" ) );
    data->addWidget( new QLabel( "17/09/1994" ) );
    data->addWidget( new QLineEdit( "17/09/1994" ) );
    job->addWidget( new QLabel( "Student" ) );
    job->addWidget( new QLineEdit( "Student" ) );

    QHBoxLayout * layoutFullName = new QHBoxLayout;
    layoutFullName->addWidget( name );
    layoutFullName->addWidget( surname );

    telephone->setCurrentIndex( 1 );

    QFormLayout * layoutInfo = new QFormLayout;
    layoutInfo->addRow( tr( "Telephone" ) + ':', telephone );
    layoutInfo->addRow( tr( "Data" ) + ':', data );
    layoutInfo->addRow( tr( "Job" ) + ':', job );

    QVBoxLayout * layoutDati = new QVBoxLayout;
    layoutDati->addLayout( layoutFullName );
    layoutDati->addLayout( layoutInfo );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( lblImage );
    layout->addLayout( layoutDati );

    setLayout( layout );
}


UserInterface_View::ID::~ID()
{
    delete name;
    delete surname;
    delete telephone;
    delete data;
    delete job;
}


UserInterface_View::Top::Top( LevelAccess level, QWidget * parent )
                              : QWidget( parent ),
                                username( new QStackedWidget ),
                                typeAccount( new QStackedWidget )

{
    QLabel * lblUser = new QLabel( tr( "Username" ) + ':' );
    username->addWidget( new QLabel( "Username" ) );
    username->addWidget( new QLineEdit( "Username" ) );

    QLabel * lblAccount = new QLabel( tr( "Account" ) + ':' );
    typeAccount->addWidget( new QLabel( "Type account" ) );
    typeAccount->addWidget( new QLabel( "Type account" ) );

    QPushButton * btmFriend = new QPushButton( tr( "Add coworker" ) );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( lblUser );
    layout->addWidget( username );
    layout->addWidget( lblAccount );
    layout->addWidget( typeAccount );
    layout->addWidget( btmFriend );

    setLayout( layout );
}


UserInterface_View::Top::~Top()
{
    delete username;
    delete typeAccount;
}


UserInterface_View::UserInterface_View( LevelAccess l, QWidget * parent )
                                        : level( l ),
                                          QWidget( parent )
{
    QScrollArea * area = new QScrollArea;

    Top * top = new Top( l );
    ID * id = new ID( l );

    QVBoxLayout * layoutUserData = new QVBoxLayout;
    layoutUserData->setAlignment( Qt::AlignTop );
    layoutUserData->addWidget( top );
    layoutUserData->addWidget( id );

    QHBoxLayout * layoutInterface = new QHBoxLayout;
    layoutInterface->addLayout( layoutUserData );

    area->setLayout( layoutInterface );

    QVBoxLayout * layout = new QVBoxLayout;
    area->setWidgetResizable( true );
    layout->addWidget( area );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{

}
