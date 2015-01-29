#include "usersearch.h"

UserSearch::UserSearch( QWidget * parent ) : QWidget( parent )
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search" ) );

    UserEditPage * editPage = new UserEditPage();

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnSearch );
    layoutButton->addWidget( btnReset );


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
