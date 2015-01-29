#include "usereditpage.h"

UserEditPage::UserEditPage( QWidget * parent ) : QWidget( parent )
{
    QScrollArea * areaForm = new QScrollArea();
    areaForm->setFrameShape( QFrame::NoFrame );
    areaForm->setWidgetResizable( true );

    ModuleID * id = new ModuleID();

    ModuleExperience * experience = new ModuleExperience();
    ModuleSkills * skills = new ModuleSkills();

    QLabel * lblId = new QLabel( tr( "Info" ) );
    QLabel * lblExperience = new QLabel( tr( "Experience" ) );

    QPushButton * btnExperience = new QPushButton( tr( "Add Experience" ) );
    btnExperience->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

    QLabel * lblSkills = new QLabel( tr( "Skills" ) );
    QPushButton * btnSkills = new QPushButton( tr( "Add Skill" ) );
    btnSkills->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Maximum );

    QHBoxLayout * layoutExperience = new QHBoxLayout();
    layoutExperience->addWidget( lblExperience );
    layoutExperience->addWidget( btnExperience );

    QHBoxLayout * layoutSkills = new QHBoxLayout();
    layoutSkills->addWidget( lblSkills );
    layoutSkills->addWidget( btnSkills );

    QVBoxLayout * layoutArea = new QVBoxLayout;
    layoutArea->setAlignment( Qt::AlignTop );
    layoutArea->addWidget( lblId );
    layoutArea->addWidget( id );
    layoutArea->addWidget( new Line() );
    layoutArea->addLayout( layoutExperience );
    layoutArea->addWidget( experience );
    layoutArea->addWidget( new Line() );
    layoutArea->addLayout( layoutSkills );
    layoutArea->addWidget( skills );

    areaForm->setLayout( layoutArea );

    QVBoxLayout * layoutTop = new QVBoxLayout;
    layoutTop->setAlignment( Qt::AlignTop );
    layoutTop->addWidget( areaForm );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addLayout( layoutTop );

    setLayout( layout );
}


UserEditPage::~UserEditPage()
{

}
