#include "usersearch.h"

void UserSearch::composeInfo() const
{
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
}


void UserSearch::manageLocalError( ErrorState::Type type )
{
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

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblError );
    layout->addLayout( layoutForm );
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
