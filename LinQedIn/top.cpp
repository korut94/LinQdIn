#include "top.h"

Top::Top( const LevelAccess::Type & level, QWidget * parent )
          : QWidget( parent )

{
    QLabel * lblUser = new QLabel( tr( "Username" ) + ": korut94" );
    QLabel * lblAccount = new QLabel( tr( "Account" ) + ": Mega master" );

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
