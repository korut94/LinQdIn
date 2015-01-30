#include "usereditpage.h"

bool UserEditPage::checkErrorForm() const
{
    bool check = experience->checkError() &&
                 id->checkError() && education->checkError();

    return check;
}


Info UserEditPage::recapInfo() const
{
    return Info( id->getDataPersonal(),
                 skills->getSkills(),
                 experience->getExperiences() );
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
}


void UserEditPage::loadModuleAccount()
{
    if( account == nullptr )
    {
        account = new ModuleAccout();
        layoutArea->addWidget( account );
    }
}


void UserEditPage::loadModuleEducation()
{
    if( education == nullptr )
    {
        education = new ModuleEducation();

        QLabel * lblEducation = new QLabel( tr( "Education" ) );
        lblEducation->setFont( QFont( "Helvetica", 12, QFont::Bold ) );
        QPushButton * btnEducation = new QPushButton( tr( "Add Education" ) );
        btnEducation->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

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


void UserEditPage::loadModuleExperience()
{
    if( experience == nullptr )
    {
        experience = new ModuleExperience();

        QLabel * lblExperience = new QLabel( tr( "Experience" ) );
        lblExperience->setFont( QFont( "Helvetica", 12, QFont::Bold ) );
        QPushButton * btnExperience = new QPushButton( tr( "Add Experience" ) );
        btnExperience->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

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


void UserEditPage::loadModuleId()
{
    if( id == nullptr )
    {
        id = new ModuleID();

        QLabel * lblId = new QLabel( tr( "Info" ) );
        lblId->setFont( QFont( "Helvetica", 12, QFont::Bold ) );

        layoutArea->addWidget( lblId );
        layoutArea->addWidget( id );
    }
}


void UserEditPage::loadModuleSkill()
{
    if( skills == nullptr )
    {
        skills = new ModuleSkills();

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


void UserEditPage::error( const QString & msg )
{
    msgError->setVisible( true );
    msgError->setText( msg );
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


