#include "boardfriends.h"

BoardFriends::BoardFriends( const LevelAccess::Type & level,
                            QWidget * parent )
                            : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );

    TableUsers * me = new TableUsers( tr( "Me" ) );
    me->setFixedHeight( 110 );
    //me->addItem( Info( "Andrea", "Mantovani", "3406936174", "17/09/1994" ) );

    QPushButton * btnModify = new QPushButton( tr( "Modified" ) );
    TableUsers * friends = new TableUsers( tr( "My cowork" ) );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( me );
    layout->addWidget( btnModify );
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
