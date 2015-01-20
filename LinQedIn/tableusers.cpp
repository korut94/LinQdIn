#include "tableusers.h"

TableUsers::TableUsers( QWidget * parent ) : QWidget( parent )
{
    QScrollArea * areaTable = new QScrollArea;
    areaTable->setMaximumWidth( 230 );
    areaTable->setStyleSheet( "QScrollArea{ background-color: white; }" );
    areaTable->setWidgetResizable( true );

    listUsers = new QWidget();
    QVBoxLayout * layoutUsers = new QVBoxLayout;

    layoutUsers->setContentsMargins( 0, 0, 0, 0 );

    for( int i = 0; i < 50; i++ )
    {
        Info info( "Andrea", "Mantovani", "3406936174", "17/09/1994" );
        UserItem * item = new UserItem( info );

        layoutUsers->addWidget( item );
    }

    listUsers->setLayout( layoutUsers );
    areaTable->setWidget( listUsers );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( areaTable );

    setLayout( layout );
}


TableUsers::~TableUsers()
{
    delete listUsers;
}
