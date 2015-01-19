#include "tableusers.h"

TableUsers::TableUsers( QWidget * parent ) : QWidget( parent )
{
    QScrollArea * areaTable = new QScrollArea;

    Info info( "Andrea", "Mantovani", "36", "6" );

    for( int i = 0; i < 50; i++ )
    {
        UserItem * item = new UserItem( info );
        areaTable->setWidget( item );
    }

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( areaTable );

    setLayout( layout );
}


TableUsers::~TableUsers()
{
}
