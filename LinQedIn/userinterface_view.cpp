#include "userinterface_view.h"

void UserInterface_View::loadMainPage()
{
    Top * top = new Top( level );
    ID * id = new ID( level );
    ViewExperience * experience = new ViewExperience( level );
    BoardFriends * boardFriends = new BoardFriends( level );

    QVBoxLayout * layoutUserData = new QVBoxLayout;
    layoutUserData->setAlignment( Qt::AlignTop );
    layoutUserData->addWidget( top );
    layoutUserData->addWidget( id );
    layoutUserData->addWidget( experience );

    QHBoxLayout * layoutInterface = new QHBoxLayout;
    layoutInterface->addLayout( layoutUserData );
    layoutInterface->addWidget( boardFriends );

    QWidget * container = new QWidget();
    container->setLayout( layoutInterface );

    userUtility->setWidget( container );

    connect( boardFriends,
             SIGNAL( modify() ),
             this,
             SIGNAL( requestModify() ) );
}


void UserInterface_View::setFrameUtility( QWidget * window )
{
    userUtility->setWidget( window );
}


UserInterface_View::UserInterface_View( LevelAccess::Type l, QWidget * parent )
                                        : level( l ),
                                          QWidget( parent )
{
    userUtility = new QScrollArea;
    userUtility->setWidgetResizable( true );

    loadMainPage();

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( userUtility );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{

}
