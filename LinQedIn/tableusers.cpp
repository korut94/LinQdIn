#include "tableusers.h"

TableUsers::TableUsers( QWidget * parent ) : QWidget( parent )
{
    setMaximumWidth( 300 );

    QScrollArea * areaTable = new QScrollArea;
    areaTable->setWidgetResizable( true );

    QVBoxLayout * layoutUsers = new QVBoxLayout;
    //Aggiunta degli utenti dall'alto verso il basso
    layoutUsers->setAlignment( Qt::AlignTop );
    layoutUsers->setContentsMargins( 0, 0, 0, 0 );

    listUsers = new QWidget();
    listUsers->setLayout( layoutUsers );
    areaTable->setWidget( listUsers );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( areaTable );
    layout->setContentsMargins( 0, 0, 0, 0 );

    setLayout( layout );
}


TableUsers::~TableUsers()
{
    delete listUsers;
}
