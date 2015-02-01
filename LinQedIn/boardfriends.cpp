#include "boardfriends.h"

BoardFriends::BoardFriends( const smartptr_utente & user,
                            QWidget * parent )
                            : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

    TableUsers * me = new TableUsers( tr( "Me" ) );
    me->setItems( QVector<Info>( 1, user->getInfo() ) );
    me->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Maximum );

    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search co-worker" ) );
    TableUsers * friends = new TableUsers( tr( "My colleagues" ) );

    const Utente::Rete & contatti = user->getContatti();
    QVector<Info> infoContatti;

    std::transform( contatti.begin(),
                    contatti.end(),
                    infoContatti.begin(),
                    [] ( const smartptr_utente & s ) -> Info
                    {
                        return s->getInfo();
                    } );

    friends->setItems( infoContatti );

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
