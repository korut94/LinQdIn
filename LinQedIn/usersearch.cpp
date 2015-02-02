#include "usersearch.h"

void UserSearch::composeInfo() const
{
    Personal personal( editName->text(), editSurname->text() );
    emit search( Info( personal ) );
}


void UserSearch::reset()
{
    editName->clear();
    editSurname->clear();
}


UserSearch::UserSearch( QWidget * parent )
                        : editName( nullptr ),
                          editSurname( nullptr ),
                          QWidget( parent )
{
}


UserSearch::~UserSearch()
{
}


QWidget * UserSearch::getView()
{
    QWidget * view = new QWidget();

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
    layout->addLayout( layoutForm );
    layout->addLayout( layoutBottom );

    view->setLayout( layout );

    connect( btnReset,
             SIGNAL( clicked() ),
             this,
             SLOT( reset() ) );

    connect( btnSearch,
             SIGNAL( clicked() ),
             this,
             SLOT( composeInfo() ) );

    return view;
}
