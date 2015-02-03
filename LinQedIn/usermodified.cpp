#include "usermodified.h"

void UserModified::checkToSanityInsert() const
{
    if( editPage->checkErrorForm() == ErrorState::None )
    {
        if( editPage->completeForm() ) emit modify( editPage->recapInfo(),
                                                    editPage->getTypeUser() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}


void UserModified::manageLocalError( ErrorState::Type type )
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


UserModified::UserModified( const smartptr_utente & user,
                            LevelAccess::Type level,
                            QWidget * parent ) : QWidget( parent )
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnApply = new QPushButton( tr( "Apply" ) );

    editPage = new UserEditPage();

    editPage->loadModuleId( user );
    if( level == LevelAccess::Master ) editPage->loadModuleAccount( user );
    editPage->loadModuleExperience( user );
    editPage->loadModuleSkill( user );
    editPage->loadModuleEducation( user );

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnApply );
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

    connect( btnApply,
             SIGNAL( clicked() ),
             this,
             SLOT( checkToSanityInsert() ) );

    connect( this,
             SIGNAL( errorMessage( const QString & ) ),
             editPage,
             SLOT( error( const QString & ) ) );
}


UserModified::~UserModified()
{
}

