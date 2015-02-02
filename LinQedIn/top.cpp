#include "top.h"

Top::Top( const smartptr_utente & user, QWidget * parent ) : QWidget( parent )

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

    QPushButton * btmFriend = new QPushButton( tr( "Add co-worker" ) );
    btmFriend->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( lblUser );
    layout->addWidget( lblAccount );
    layout->addWidget( btmFriend );

    setLayout( layout );
}


Top::~Top()
{
}
