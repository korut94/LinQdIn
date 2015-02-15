#include "top.h"

void Top::setAddFriend()
{
    setFriend( true );
    emit amici();
}


void Top::setFriend( bool state )
{
    if( state )
    {
        btnFriend->setText( tr( "Remove colleague" ) );

        disconnect( btnFriend,
                    SIGNAL( clicked() ),
                    this,
                    SLOT( setAddFriend()) );

        connect( btnFriend,
                 SIGNAL( clicked() ),
                 this,
                 SLOT( setRemoveFriend() ) );
    }

    else
    {
        btnFriend->setText( tr( "Add colleague" ) );

        disconnect( btnFriend,
                    SIGNAL( clicked() ),
                    this,
                    SLOT( setRemoveFriend() ) );

        connect( btnFriend,
                 SIGNAL( clicked() ),
                 this,
                 SLOT( setAddFriend() ) );
    }

}


void Top::setRemoveFriend()
{
    setFriend( false );
    emit nonAmici();
}


Top::Top( const smartptr_utente & user,
          LevelAccess::Type level,
          QWidget * parent ) : btnFriend( nullptr ), QWidget( parent )

{
    QLabel * lblUser = new QLabel( tr( "Username" ) +
                                   ": " +
                                   user->getUsername() );

    QString l;

    switch( user->typeAccount() )
    {
        case LevelAccess::Basic : l = "Basic";
                                  break;
        case LevelAccess::Business : l = "Business";
                                     break;
        case LevelAccess::Executive : l = "Executive";
                                      break;
        default : l = "Basic";
    }

    QLabel * lblAccount = new QLabel( tr( "Account" ) + ": " + l );

    QPushButton * btnHome = new QPushButton( tr( "Home" ) );
    btnHome->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( btnHome );
    layout->addWidget( lblUser );
    layout->addWidget( lblAccount );

    if( level > LevelAccess::I )
    {
        btnFriend = new QPushButton( tr( "Add co-worker" ) );
        btnFriend->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

        layout->addWidget( btnFriend );

        setFriend( false );
    }

    setLayout( layout );

    connect( btnHome,
             SIGNAL( clicked() ),
             this,
             SIGNAL( home() ) );
}


Top::~Top()
{
}
