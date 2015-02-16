#include "viewbusiness.h"

ViewBusiness::ViewBusiness( QWidget * parent ) : ViewBase( parent )
{
}


void ViewBusiness::loadMainPage( const smartptr_utente & user )
{
    ViewBasic * basic = new ViewBasic();
    basic->loadMainPage( user );
    basic->layout()->setMargin( 0 );

    ViewExperience * experience = new ViewExperience( user->getInfo() );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->setAlignment( Qt::AlignTop );
    layout->addWidget( basic );
    layout->addWidget( experience );

    setLayout( layout );

    connect( basic,
             SIGNAL( requestAddFriend() ),
             this,
             SIGNAL( requestAddFriend() ) );

    connect( basic,
             SIGNAL( requestRemoveFriend() ),
             this,
             SIGNAL( requestRemoveFriend() ) );

    connect( basic,
             SIGNAL( requestHome() ),
             this,
             SIGNAL( requestHome() ) );

    connect( this,
             SIGNAL( topSetFriend( bool ) ),
             basic,
             SIGNAL( topSetFriend( bool ) ) );
}
