#include "usersearch.h"

void UserSearch::recapInfo()
{
    Info info( editName->text(), "Mantovani", "", "" );

    emit searchUser( info );
}


UserSearch::UserSearch( QWidget * parent ) : QWidget( parent )
{
    QLabel * lblName = new QLabel( tr( "Name:" ) );
    editName = new QLineEdit();
    QPushButton * btmReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btmSearch = new QPushButton( tr( "Search" ) );

    QScrollArea * areaForm = new QScrollArea();
    areaForm->setFrameShape( QFrame::NoFrame );
    areaForm->setWidgetResizable( true );

    QLabel * line = new QLabel();
    line->setFrameStyle( QFrame::HLine | QFrame::Plain );
    line->setLineWidth( 1 );

    QHBoxLayout * layoutName = new QHBoxLayout;
    layoutName->addWidget( lblName );
    layoutName->addWidget( editName );

    QVBoxLayout * layoutForm = new QVBoxLayout;
    layoutForm->setAlignment( Qt::AlignTop );
    layoutForm->addLayout( layoutName );

    QWidget * container = new QWidget();
    container->setLayout( layoutForm );

    areaForm->setWidget( container );

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btmSearch );
    layoutButton->addWidget( btmReset );

    QVBoxLayout * layoutTop = new QVBoxLayout;
    layoutTop->setAlignment( Qt::AlignTop );
    layoutTop->addWidget( areaForm );

    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( line );
    layoutBottom->addLayout( layoutButton );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addLayout( layoutTop );
    layout->addLayout( layoutBottom );

    setLayout( layout );

    connect( btmSearch, SIGNAL( clicked() ), this, SLOT( recapInfo() ) );
}


UserSearch::~UserSearch()
{
    delete editName;
}
