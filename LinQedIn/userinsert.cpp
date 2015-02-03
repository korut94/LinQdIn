#include "userinsert.h"

LevelAccess::Type UserInsert::getAccoutTypeSet() const
{
    return editPage->getTypeUser();
}


void UserInsert::checkToSanityInsert() const
{
    if( editPage->checkErrorForm() == ErrorState::None )
    {
        if( editPage->completeForm() ) emit insert( editPage->recapInfo() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}


void UserInsert::manageLocalError( ErrorState::Type type )
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


UserInsert::UserInsert()
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnInsert = new QPushButton( tr( "Insert" ) );

    editPage = new UserEditPage();

    editPage->loadModuleId();
    editPage->loadModuleAccount();
    editPage->loadModuleExperience();
    editPage->loadModuleSkill();
    editPage->loadModuleEducation();

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnInsert );
    layoutButton->addWidget( btnReset );

    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( new Line() );
    layoutBottom->addLayout( layoutButton );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( editPage );
    layout->addLayout( layoutBottom );

    setLayout( layout );

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

    connect( btnInsert,
             SIGNAL( clicked() ),
             this,
             SLOT( checkToSanityInsert() ) );

    connect( this,
             SIGNAL( errorMessage( const QString & ) ),
             editPage,
             SLOT( error( const QString & ) ) );
}


UserInsert::~UserInsert()
{
}
