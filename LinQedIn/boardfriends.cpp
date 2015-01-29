#include "boardfriends.h"

BoardFriends::BoardFriends( const LevelAccess::Type & level,
                            QWidget * parent )
                            : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

    TableUsers * me = new TableUsers( tr( "Me" ) );
    me->setFixedHeight( 110 );

    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search cowork" ) );
    TableUsers * friends = new TableUsers( tr( "My colleagues" ) );

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
