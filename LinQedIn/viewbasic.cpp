#include "viewbasic.h"

ViewBasic::ViewBasic( QWidget * parent ) : ViewOther( parent )
{
}


ViewBasic::~ViewBasic()
{
}


void ViewBasic::loadMainPage( const smartptr_utente & user )
{
    Top * top = new Top( user, LevelAccess::Basic );
    ID * id = new ID( user->getInfo().getPersonal() );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->addWidget( top );
    layout->addWidget( id );

    setLayout( layout );

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
