#include "userinsert.h"

UserInsert::UserInsert()
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnInsert = new QPushButton( tr( "Insert" ) );

    UserEditPage * editPage = new UserEditPage();
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
}


UserInsert::~UserInsert()
{

}
