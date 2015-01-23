#include "usersearch.h"

void UserSearch::recapInfo()
{
    Info info( editName->text(), "Mantovani", "", "" );

    emit searchUser( info );
}


UserSearch::UserSearch( QWidget * parent ) : QWidget( parent )
{
    QLabel * lblName = new QLabel( "Name" );
    editName = new QLineEdit();
    QPushButton * btm = new QPushButton( "Push" );

    QHBoxLayout * layoutName = new QHBoxLayout;
    layoutName->addWidget( lblName );
    layoutName->addWidget( editName );
    layoutName->addWidget( btm );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addLayout( layoutName );

    setLayout( layout );

    connect( btm, SIGNAL( clicked() ), this, SLOT( recapInfo() ) );
}


UserSearch::~UserSearch()
{
    delete editName;
}
