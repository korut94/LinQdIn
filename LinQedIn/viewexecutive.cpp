#include "viewexecutive.h"

ViewExecutive::ViewExecutive( QWidget * parent ) : ViewOther( parent )
{
}


ViewExecutive::~ViewExecutive()
{

}


void ViewExecutive::loadMainPage( const smartptr_utente & user )
{
    ViewBusiness * business = new ViewBusiness();
    business->loadMainPage( user );
    business->layout()->setMargin( 0 );

    BoardFriends * boardFriends = new BoardFriends( user );
    boardFriends->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

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

    connect( this,
             SIGNAL( viewListFriends( const Utente::Rete & ) ),
             boardFriends,
             SLOT( viewFriends( const Utente::Rete & ) ) );

    connect( boardFriends,
             SIGNAL( select( const QString & ) ),
             this,
             SIGNAL( requestViewFriend( const QString & ) ) );
}
