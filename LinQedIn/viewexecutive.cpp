#include "viewexecutive.h"

ViewExecutive::ViewExecutive( QWidget * parent ) : ViewBase( parent )
{
}


void ViewExecutive::loadMainPage( const smartptr_utente & user )
{
    ViewBusiness * business = new ViewBusiness();
    business->loadMainPage( user );
    business->layout()->setMargin( 0 );

    BoardFriends * boardFriends = new BoardFriends( user );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->addWidget( business );
    layout->addWidget( boardFriends );

    setLayout( layout );

    connect( business,
             SIGNAL( requestAddFriend() ),
             this,
             SIGNAL( requestAddFriend() ) );

    connect( business,
             SIGNAL( requestRemoveFriend() ),
             this,
             SIGNAL( requestRemoveFriend() ) );

    connect( business,
             SIGNAL( requestHome() ),
             this,
             SIGNAL( requestHome() ) );

    connect( this,
             SIGNAL( topSetFriend( bool ) ),
             business,
             SIGNAL( topSetFriend( bool ) ) );

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
}
