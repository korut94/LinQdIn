#include "userinsert.h"

void UserInsert::checkToSanityInsert() const
{
    if( checkErrorForm() == ErrorState::None )
    {
        if( completeForm() ) emit insert( recapInfo(), getTypeUser() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}


void UserInsert::manageLocalError( ErrorState::Type type )
{
    switch( type )
    {
        case ErrorState::InvalidValue :
             displayError( tr( "Incorrect values" ) );
             break;

        case ErrorState::EmptyValue :
             displayError( tr( "Empty values" ) );
             break;
    }
}


UserInsert::UserInsert()
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnInsert = new QPushButton( tr( "Insert" ) );

    loadModuleId();
    loadModuleAccount();
    loadModuleExperience();
    loadModuleSkill();
    loadModuleEducation();

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnInsert );
    layoutButton->addWidget( btnReset );

    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( new Line() );
    layoutBottom->addLayout( layoutButton );

    QVBoxLayout * layout =
            dynamic_cast<QVBoxLayout*>( UserEditPage::layout() );
    if( layout != nullptr )
    {
        layout->addLayout( layoutBottom );
        setLayout( layout );
    }

    connect( this,
             SIGNAL( requestAddEducation() ),
             this,
             SLOT( addEducation() ) );

    connect( this,
             SIGNAL( requestAddExperience() ),
             this,
             SLOT( addExperience() ) );

    connect( this,
             SIGNAL( requestAddSkill() ),
             this,
             SLOT( addSkill() ) );

    connect( btnReset,
             SIGNAL( clicked() ),
             this,
             SLOT( reset() ) );

    connect( btnInsert,
             SIGNAL( clicked() ),
             this,
             SLOT( checkToSanityInsert() ) );
}


UserInsert::~UserInsert()
{
}
