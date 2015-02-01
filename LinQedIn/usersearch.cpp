#include "usersearch.h"

void UserSearch::manageLocalError( ErrorState::Type type )
{
    switch( type )
    {
        case ErrorState::InvalidValue :
             emit errorMessage( tr( "Incorrect values" ) );
             break;

        case ErrorState::EmptyValue :
             emit errorMessage( tr( "Empty values" ) );
             break;
    }
}


void UserSearch::checkToSanityInsert() const
{
    if( editPage->checkErrorForm() == ErrorState::None )
    {
        if( editPage->completeForm() ) emit search( editPage->recapInfo() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}


UserSearch::UserSearch( LevelAccess::Type l, QWidget * parent )
                        : QWidget( parent ), level( l )
{

}


UserSearch::~UserSearch()
{
}


QWidget * UserSearch::getView() const
{
    QWidget * view = new QWidget();

    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnSearch = new QPushButton( tr( "Search" ) );

    editPage->loadModuleId();
    editPage->loadModuleExperience();
    editPage->loadModuleSkill();
    editPage->loadModuleEducation();

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

    view->setLayout( layout );

    connect( editPage,
             SIGNAL( requestAddEducation() ),
             editPage,
             SLOT( addEducation() ) );

    connect( editPage,
             SIGNAL( requestAddExperience() ),
             editPage,
             SLOT( addExperience() ) );

    connect( editPage,
             SIGNAL( requestAddSkill() ),
             editPage,
             SLOT( addSkill() ) );

    connect( btnReset,
             SIGNAL( clicked() ),
             editPage,
             SLOT( reset() ) );

    connect( btnSearch,
             SIGNAL( clicked() ),
             this,
             SLOT( checkToSanityInsert() ) );

    connect( this,
             SIGNAL( errorMessage( const QString & ) ),
             editPage,
             SLOT( error( const QString &) ) );

    return view;
}
