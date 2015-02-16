#include "viewi.h"

ViewI::ViewI( QWidget * parent ) : ViewBase( parent )
{
}


void ViewI::loadMainPage( const smartptr_utente & user )
{
    Top * top = new Top( user, LevelAccess::I );
    ID * id = new ID( user->getInfo().getPersonal() );

    QVBoxLayout * layoutUserData = new QVBoxLayout;
    layoutUserData->setAlignment( Qt::AlignTop );
    layoutUserData->addWidget( top );
    layoutUserData->addWidget( id );

    ViewExperience * experience = new ViewExperience( user->getInfo() );
    layoutUserData->addWidget( experience );

    QHBoxLayout * layoutInterface = new QHBoxLayout;
    layoutInterface->addLayout( layoutUserData );

    BoardFriends * boardFriends = new BoardFriends( user );
    layoutInterface->addWidget( boardFriends );

    setLayout( layoutInterface );

    connect( boardFriends,
             SIGNAL( modify() ),
             this,
             SIGNAL( requestModify() ) );

    connect( boardFriends,
             SIGNAL( logout() ),
             this,
             SIGNAL( requestLogout() ) );

    connect( boardFriends,
             SIGNAL( search() ),
             this,
             SIGNAL( requestSearch() ) );

    connect( this,
             SIGNAL( viewListFriends( const Utente::Rete & ) ),
             boardFriends,
             SLOT( viewFriends( const Utente::Rete & ) ) );

    connect( boardFriends,
             SIGNAL( select( const QString & ) ),
             this,
             SIGNAL( requestViewFriend( const QString & ) ) );

    connect( top,
             SIGNAL( amici() ),
             this,
             SIGNAL( requestAddFriend() ) );

    connect( top,
             SIGNAL( nonAmici() ),
             this,
             SIGNAL( requestRemoveFriend() ) );

    connect( top,
             SIGNAL( home() ),
             this,
             SIGNAL( requestHome() ) );

    connect( this,
             SIGNAL( topSetFriend( bool ) ),
             top,
             SLOT( setFriend( bool ) ) );
}
