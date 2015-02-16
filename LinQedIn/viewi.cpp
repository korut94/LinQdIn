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
    QPushButton * btnLogout = new QPushButton( tr( "Logout" ) );
    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search colleagues" ) );

    QVBoxLayout * layoutRight = new QVBoxLayout;
    layoutRight->addWidget( btnLogout );
    layoutRight->addWidget( btnModify );
    layoutRight->addWidget( btnSearch );
    layoutRight->addWidget( boardFriends );

    layoutInterface->addLayout( layoutRight );

    setLayout( layoutInterface );

    connect( btnModify,
             SIGNAL( clicked() ),
             this,
             SIGNAL( requestModify() ) );

    connect( btnLogout,
             SIGNAL( clicked() ),
             this,
             SIGNAL( requestLogout() ) );

    connect( btnSearch,
             SIGNAL( clicked() ),
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
