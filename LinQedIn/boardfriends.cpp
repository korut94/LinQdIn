#include "boardfriends.h"

BoardFriends::BoardFriends( const smartptr_utente & user,
                            QWidget * parent )
                            : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

    TableUsers * me = new TableUsers( tr( "Me" ) );
    me->setItems( QVector<smartptr_utente>( 1, user ) );
    me->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Maximum );

    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search co-worker" ) );
    TableUsers * friends = new TableUsers( tr( "My colleagues" ) );

    const Utente::Rete & contatti = user->getContatti();
    friends->setItems( contatti.toVector() );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( me );
    layout->addWidget( btnModify );
    layout->addWidget( btnSearch );
    layout->addWidget( friends );

    setLayout( layout );

    QObject::connect( btnModify,
                      SIGNAL( clicked() ),
                      this,
                      SIGNAL( modify() ) );
}


BoardFriends::~BoardFriends()
{
}
