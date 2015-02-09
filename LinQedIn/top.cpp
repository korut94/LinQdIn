#include "top.h"

void Top::setAddFriend()
{
    btnFriend->setText( tr( "Remove co-worker" ) );

    disconnect( btnFriend,
                SIGNAL( clicked() ),
                this,
                SLOT( setAddFriend()) );

    connect( btnFriend,
             SIGNAL( clicked() ),
             this,
             SLOT( setRemoveFriend() ) );

    emit amici();
}


void Top::setRemoveFriend()
{
    btnFriend->setText( tr( "Add co-worker" ) );

    disconnect( btnFriend,
                SIGNAL( clicked() ),
                this,
                SLOT( setRemoveFriend()) );

    connect( btnFriend,
             SIGNAL( clicked() ),
             this,
             SLOT( setAddFriend() ) );

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

        connect( btnFriend,
                 SIGNAL( clicked() ),
                 this,
                 SLOT( setAddFriend() ) );
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
