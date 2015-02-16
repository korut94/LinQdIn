#include "viewexecutive.h"

ViewExecutive::ViewExecutive( QWidget * parent ) : ViewBase( parent )
{
}


void ViewExecutive::loadMainPage( const smartptr_utente & user )
{
    ViewBusiness * business = new ViewBusiness();
    business->loadMainPage( user );
    business->layout()->setMargin( 0 );

    BoardFriends * boardFriend = new BoardFriends( user );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->addWidget( business );
    layout->addWidget( boardFriend );

    setLayout( layout );
}
