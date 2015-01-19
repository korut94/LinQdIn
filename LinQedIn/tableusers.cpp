#include "tableusers.h"

TableUsers::TableUsers( QWidget * parent ) : QWidget( parent )
{
    QScrollArea * areaTable = new QScrollArea;
    areaTable->setMaximumWidth( 200 );

    areaTable->setStyleSheet( "QScrollArea{ background-color: white; }" );

    users = new QWidget();
    QVBoxLayout * layoutUsers = new QVBoxLayout;

    layoutUsers->setContentsMargins( 0, 0, 0, 0 );

    for( int i = 0; i < 50; i++ )
    {
        Info info( "Andrea", "Mantovani", "36", "6" );
        UserItem * item = new UserItem( info );

        layoutUsers->addWidget( item );
    }

    users->setLayout( layoutUsers );
    areaTable->setWidget( users );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( areaTable );

    setLayout( layout );
}


TableUsers::~TableUsers()
{
    delete users;
}
