#include "usersearch.h"

void UserSearch::recapInfo()
{
    Info info( editName->text(), "Mantovani", "", "" );
    std::cout << info.getNome().toStdString() << std::endl;

    emit searchUser( info );
}


UserSearch::UserSearch( QWidget * parent ) : QWidget( parent )
{
    QLabel * lblName = new QLabel( tr( "Name" ) );
    QLineEdit * editName = new QLineEdit();
    QPushButton * btm = new QPushButton();

    QHBoxLayout * layoutName = new QHBoxLayout;
    layoutName->addWidget( lblName );
    layoutName->addWidget( editName );
    layoutName->addWidget( btm );

    QVBoxLayout * layout = new QVBoxLayout;

    setLayout( layout );

    connect( btm, SIGNAL( clicked() ), this, SLOT( recapInfo() ) );
}


UserSearch::~UserSearch()
{
    delete editName;
}
