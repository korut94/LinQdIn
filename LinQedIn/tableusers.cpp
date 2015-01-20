#include "tableusers.h"

void TableUsers::addUser()
{
    QLayout * layout = listUsers->layout();
    layout->addWidget( new UserItem( Info( "Andrea",
                                           "Mantovani",
                                           "3406936174",
                                           "17/09/1994" ) ) );

    listUsers->setLayout( layout );
}


TableUsers::TableUsers( QWidget * parent ) : QWidget( parent )
{
    setMaximumWidth( 230 );

    QScrollArea * areaTable = new QScrollArea;
    areaTable->setStyleSheet( "QScrollArea{ background-color: white; }" );
    areaTable->setWidgetResizable( true );

    QVBoxLayout * layoutUsers = new QVBoxLayout;
    //Aggiunta degli utenti dall'alto verso il basso
    layoutUsers->setAlignment( Qt::AlignTop );
    layoutUsers->setContentsMargins( 0, 0, 0, 0 );

    listUsers = new QWidget();
    listUsers->setLayout( layoutUsers );
    areaTable->setWidget( listUsers );

    QPushButton * add = new QPushButton( "Add" );
    QPushButton * remove = new QPushButton( "Remove" );

    QHBoxLayout * layoutBtm = new QHBoxLayout;
    layoutBtm->addWidget( add );
    layoutBtm->addWidget( remove );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addLayout( layoutBtm );
    layout->addWidget( areaTable );

    setLayout( layout );

    connect( add, SIGNAL( clicked() ), this, SLOT( addUser() ) );
}


TableUsers::~TableUsers()
{
    delete listUsers;
}
