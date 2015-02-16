#include "usersearch.h"

void UserSearch::composeInfo() const
{
    lblError->setVisible( false );

    QVector<smartptr_utente> risp =
            database->getUsers(
                SearchGroupUtente::ByNameAndSurname( editName->text(),
                                                     editSurname->text() ) );

    if( risp.isEmpty() ) emit error( ErrorState::NotFoundUser );
    else emit search( risp );
}


void UserSearch::reset()
{
    editName->clear();
    editSurname->clear();
    lblError->setVisible( false );
}


void UserSearch::manageLocalError( ErrorState::Type type )
{
    lblError->setVisible( true );

    switch( type )
    {
        case ErrorState::InvalidValue :
             lblError->setText( tr( "Incorrect values" ) );
             break;

        case ErrorState::EmptyValue :
             lblError->setText( tr( "Empty values" ) );
             break;

        case ErrorState::NotFoundUser :
             lblError->setText( tr( "User not found" ) );
             break;
    }
}


UserSearch::UserSearch( Database * db, QWidget * parent )
                        : lblError( new QLabel() ),
                          editName( nullptr ),
                          editSurname( nullptr ),
                          database( db ),
                          QWidget( parent )
{
    lblError->setVisible( false );

    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search" ) );

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnSearch );
    layoutButton->addWidget( btnReset );

    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( new Line() );
    layoutBottom->addLayout( layoutButton );

    editName = new QLineEdit();
    editSurname = new QLineEdit();

    QFormLayout * layoutForm = new QFormLayout();
    layoutForm->addRow( tr( "Name" ) + ':', editName );
    layoutForm->addRow( tr( "Surname" ) + ':', editSurname );

    QVBoxLayout * layoutArea = new QVBoxLayout;
    layoutArea->setAlignment( Qt::AlignTop );
    layoutArea->addWidget( lblError );
    layoutArea->addLayout( layoutForm );

    QScrollArea * area = new QScrollArea();
    area->setFrameShape( QFrame::NoFrame );
    area->setLayout( layoutArea );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( area );
    layout->addLayout( layoutBottom );

    setLayout( layout );

    connect( btnReset,
             SIGNAL( clicked() ),
             this,
             SLOT( reset() ) );

    connect( btnSearch,
             SIGNAL( clicked() ),
             this,
             SLOT( composeInfo() ) );
}


UserSearch::~UserSearch()
{
}
