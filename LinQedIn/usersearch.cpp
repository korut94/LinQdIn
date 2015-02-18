#include "usersearch.h"

UserSearch::UserSearch( Database * db, QWidget * parent )
                        : database( db ),
                          UserEditPage( parent )
{
    loadModuleId();
    loadModuleExperience();
    loadModuleSkill();
    loadModuleEducation();

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

    connect( btnSearch,
             SIGNAL( clicked() ),
             this,
             SLOT( checkToSanityInsert() ) );
}


UserSearch::~UserSearch()
{
}


void UserSearch::checkToSanityInsert() const
{
    if( checkErrorForm() == ErrorState::None )
    {
        QVector<smartptr_utente> risp =
                database->getUsers( SearchGroupUtente::ByInfo( recapInfo() ) );

        if( risp.isEmpty() ) emit error( ErrorState::NotFoundUser );
        else emit search( risp );
    }

    else emit error( ErrorState::InvalidValue );
}
