#include "usersearch.h"

UserSearch::UserSearch( QWidget * parent ) : QWidget( parent )
{
    QPushButton * btmReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btmSearch = new QPushButton( tr( "Search" ) );

    UserEditPage * editPage = new UserEditPage();

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btmSearch );
    layoutButton->addWidget( btmReset );


    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( new Line() );
    layoutBottom->addLayout( layoutButton );


    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( editPage );
    layout->addLayout( layoutBottom );

    setLayout( layout );
}


UserSearch::~UserSearch()
{
}
