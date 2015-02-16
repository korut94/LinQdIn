#include "usermodified.h"

void UserModified::checkToSanityInsert() const
{
    if( checkErrorForm() == ErrorState::None )
    {
        if( completeForm() ) emit modify( recapInfo(), getTypeUser() );
        else emit error( ErrorState::EmptyValue );
    }

    else emit error( ErrorState::InvalidValue );
}


UserModified::UserModified( const smartptr_utente & user,
                            LevelAccess::Type level,
                            QWidget * parent ) : UserEditPage( parent )
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnApply = new QPushButton( tr( "Apply" ) );

    loadModuleId( user );
    if( level == LevelAccess::Master ) loadModuleAccount( user );
    loadModuleExperience( user );
    loadModuleSkill( user );
    loadModuleEducation( user );

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnApply );
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

    connect( btnApply,
             SIGNAL( clicked() ),
             this,
             SLOT( checkToSanityInsert() ) );
}


UserModified::~UserModified()
{
}

