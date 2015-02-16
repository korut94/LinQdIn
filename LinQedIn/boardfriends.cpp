#include "boardfriends.h"

void BoardFriends::viewFriends( const Utente::Rete & contatti )
{
    friends->setItems( contatti.toVector() );
}


BoardFriends::BoardFriends( const smartptr_utente & user,
                            QWidget * parent )
                            : QWidget( parent )
{
    friends = new TableUsers( tr( "My colleagues" ) );

    const Utente::Rete & contatti = user->getContatti();
    friends->setItems( contatti.toVector() );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( friends );

    setLayout( layout );

    connect( friends,
             SIGNAL( selectUser( const QString & ) ),
             this,
             SIGNAL( select( const QString & ) ) );
}


BoardFriends::~BoardFriends()
{
}
