#include "usereditpage.h"

bool UserEditPage::completeForm() const
{
    bool complete = true;

    if( education != nullptr ) complete = education->complete();
    if( experience != nullptr && complete ) complete = experience->complete();
    if( id != nullptr && complete ) complete = id->complete();
    if( skills != nullptr && complete ) complete = skills->complete();

    return complete;
}


ErrorState::Type UserEditPage::checkErrorForm() const
{
    bool check = id->checkError();

    if( check ) return ErrorState::None;
    else return ErrorState::InvalidValue;
}


Info UserEditPage::recapInfo() const
{
    Info result;

    if( id != nullptr ) result.setPersonal( id->getDatePersonal() );
    if( skills != nullptr ) result.setSkills( skills->getSkills() );
    if( experience != nullptr )
    {
        result.setWorkExperiences( experience->getExperiences() );
    }
    if( education != nullptr )
    {
        result.setSchoolExperiences( education->getEducations() );
    }

    return result;
}


LevelAccess::Type UserEditPage::getTypeUser() const
{
    account->getTypeAccount();
}


void UserEditPage::addEducation()
{
    education->addEducation();
}


void UserEditPage::addExperience()
{
    experience->addExperience();
}


void UserEditPage::addSkill()
{
    skills->addSkill();
}



void UserEditPage::reset()
{
    if( account != nullptr ) account->reset();
    if( experience != nullptr ) experience->reset();
    if( id != nullptr ) id->reset();
    if( skills != nullptr ) skills->reset();
    if( education != nullptr ) education->reset();
    if( msgError != nullptr ) msgError->setVisible( false );
}


void UserEditPage::loadModuleAccount( const smartptr_utente & user )
{
    if( account == nullptr )
    {
        account = new ModuleAccout( user );
        layoutArea->addWidget( account );
    }
}


void UserEditPage::loadModuleEducation( const smartptr_utente & user )
{
    if( education == nullptr )
    {
        education = new ModuleEducation();
        if( user != nullptr )
            education->setContent( user->getInfo().getSchoolExperiences() );

        QLabel * lblEducation = new QLabel( tr( "Education" ) );
        lblEducation->setFont( QFont( "Helvetica", 12, QFont::Bold ) );
        QPushButton * btnEducation = new QPushButton( tr( "Add Education" ) );
        btnEducation->setSizePolicy( QSizePolicy::Fixed,
                                     QSizePolicy::Maximum );

        QHBoxLayout * layoutEducation = new QHBoxLayout();
        layoutEducation->addWidget( lblEducation );
        layoutEducation->addWidget( btnEducation );

        layoutArea->addWidget( new Line() );
        layoutArea->addLayout( layoutEducation );
        layoutArea->addWidget( education );

        connect( btnEducation,
                 SIGNAL( clicked() ),
                 this,
                 SIGNAL( requestAddEducation() ) );
    }
}


void UserEditPage::loadModuleExperience( const smartptr_utente & user )
{
    if( experience == nullptr )
    {
        experience = new ModuleExperience();
        if( user != nullptr )
            experience->setContent( user->getInfo().getWorkExperiences() );

        QLabel * lblExperience = new QLabel( tr( "Experience" ) );
        lblExperience->setFont( QFont( "Helvetica", 12, QFont::Bold ) );
        QPushButton * btnExperience =
                      new QPushButton( tr( "Add Experience" ) );
        btnExperience->setSizePolicy( QSizePolicy::Fixed,
                                      QSizePolicy::Maximum );

        QHBoxLayout * layoutExperience = new QHBoxLayout();
        layoutExperience->addWidget( lblExperience );
        layoutExperience->addWidget( btnExperience );

        layoutArea->addWidget( new Line() );
        layoutArea->addLayout( layoutExperience );
        layoutArea->addWidget( experience );

        connect( btnExperience,
                 SIGNAL( clicked() ),
                 this,
                 SIGNAL( requestAddExperience() ) );
    }
}


void UserEditPage::loadModuleId( const smartptr_utente & user )
{
    if( id == nullptr )
    {
        id = new ModuleID();
        if( user != nullptr ) id->setContent( user->getInfo().getPersonal() );

        QLabel * lblId = new QLabel( tr( "Info" ) );
        lblId->setFont( QFont( "Helvetica", 12, QFont::Bold ) );

        layoutArea->addWidget( lblId );
        layoutArea->addWidget( id );
    }
}


void UserEditPage::loadModuleSkill( const smartptr_utente & user )
{
    if( skills == nullptr )
    {
        skills = new ModuleSkills();
        if( user != nullptr )
            skills->setContent( user->getInfo().getSkills() );

        QLabel * lblSkills = new QLabel( tr( "Skills" ) );
        lblSkills->setFont( QFont( "Helvetica", 12, QFont::Bold ) );
        QPushButton * btnSkills = new QPushButton( tr( "Add Skill" ) );
        btnSkills->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

        QHBoxLayout * layoutSkills = new QHBoxLayout();
        layoutSkills->addWidget( lblSkills );
        layoutSkills->addWidget( btnSkills );

        layoutArea->addWidget( new Line() );
        layoutArea->addLayout( layoutSkills );
        layoutArea->addWidget( skills );

        connect( btnSkills,
                 SIGNAL( clicked() ),
                 this,
                 SIGNAL( requestAddSkill() ) );
    }
}


void UserEditPage::displayError( const QString & msg )
{
    msgError->setVisible( true );
    msgError->setText( msg );
}


void UserEditPage::manageLocalError( ErrorState::Type type )
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


UserEditPage::UserEditPage( QWidget * parent ) :
                            account( nullptr ),
                            experience( nullptr ),
                            id( nullptr ),
                            skills( nullptr ),
                            education( nullptr ),
                            QWidget( parent )
{
    QScrollArea * areaForm = new QScrollArea();
    areaForm->setFrameShape( QFrame::NoFrame );
    areaForm->setWidgetResizable( true );

    msgError = new QLabel();
    msgError->setStyleSheet( "QLabel{ color: red; }" );
    msgError->setVisible( false );

    layoutArea = new QVBoxLayout;
    layoutArea->setAlignment( Qt::AlignTop );
    layoutArea->addWidget( msgError );

    QWidget * content = new QWidget();
    content->setLayout( layoutArea );

    areaForm->setWidget( content );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->addWidget( areaForm );

    setLayout( layout );
}


UserEditPage::~UserEditPage()
{
}


