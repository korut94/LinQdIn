#include "boardfriends.h"

void BoardFriends::viewFriends( const Utente::Rete & contatti )
{
    friends->setItems( contatti.toVector() );
}


BoardFriends::BoardFriends( const smartptr_utente & user,
                            QWidget * parent )
                            : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

    QPushButton * btnLogout = new QPushButton( tr( "Logout" ) );

    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search co-worker" ) );
    friends = new TableUsers( tr( "My colleagues" ) );

    const Utente::Rete & contatti = user->getContatti();
    friends->setItems( contatti.toVector() );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( btnLogout );
    layout->addWidget( btnModify );
    layout->addWidget( btnSearch );
    layout->addWidget( friends );

    setLayout( layout );

    QObject::connect( btnModify,
                      SIGNAL( clicked() ),
                      this,
                      SIGNAL( modify() ) );

    connect( btnLogout,
             SIGNAL( clicked() ),
             this,
             SIGNAL( logout() ) );

    connect( btnSearch,
             SIGNAL( clicked() ),
             this,
             SIGNAL( search() ) );
}


BoardFriends::~BoardFriends()
{
}
