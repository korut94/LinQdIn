#include "userinterface_view.h"

void UserInterface_View::loadMainPage( const smartptr_utente & user,
                                       LevelAccess::Type level )
{
    Top * top = new Top( user, level );
    ID * id = new ID( user->getInfo().getPersonal() );
    ViewExperience * experience = new ViewExperience( user->getInfo() );
    BoardFriends * boardFriends = new BoardFriends( user );

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


UserInterface_View::UserInterface_View( const smartptr_utente & user,
                                        LevelAccess::Type l,
                                        QWidget * parent )
                                        : QWidget( parent )
{
    userUtility = new QScrollArea;
    userUtility->setWidgetResizable( true );

    loadMainPage( user, l );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( userUtility );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{

}
