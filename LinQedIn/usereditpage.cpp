#include "usereditpage.h"

UserEditPage::ModuleExperience::
ModuleQualifica::ModuleQualifica( QWidget * parent ) : QWidget( parent )
{
    editExp = new LineEditValidate( QRegExp( "[A-Za-z]*" ) );
    editCompany = new QLineEdit();
    editDurata = new QLineEdit();
    editDescrizione = new QTextEdit();

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( editExp );
    layout->addWidget( editCompany );
    layout->addWidget( editDurata );
    layout->addWidget( editDescrizione );

    setLayout( layout );
}


UserEditPage::ModuleExperience::ModuleQualifica::~ModuleQualifica()
{
    delete editExp;
    delete editCompany;
    delete editDurata;
    delete editDescrizione;
}


Experience UserEditPage::ModuleExperience::
           ModuleQualifica::getExperience() const
{
    return Experience( editExp->text(),
                       editCompany->text(),
                       editDurata->text(),
                       editDescrizione->toPlainText() );
}


UserEditPage::ModuleExperience::ModuleExperience( QWidget * parent )
                                                  : QWidget( parent )
{
    setLayout( new QVBoxLayout );
}


UserEditPage::ModuleExperience::~ModuleExperience()
{

}


QVector<Experience> UserEditPage::ModuleExperience::getExperiences() const
{
    QVector<Experience> experiences;

    std::transform( listaQualifica.begin(),
                    listaQualifica.end(),
                    experiences.begin(),
                    [] ( ModuleQualifica * p ) -> Experience
                    {
                        return p->getExperience();
                    } );

    return experiences;
}



UserEditPage::ModuleID::ModuleID( QWidget * parent ) : QWidget( parent )
{
    editName = new LineEditValidate( QRegExp( "[a-zA-Z]" ) );

    editSurname = new LineEditValidate( QRegExp( "[A-Za-z]" ) );

    editPrefixNumber = new LineEditValidate( QRegExp( "+[0-9]{1,4}" ) );
    editPrefixNumber->setFixedWidth( 40 );
    editPrefixNumber->setMaxLength( 5 );
    editNumber = new LineEditValidate( QRegExp( "[0-9]*-[0-9]*" ) );

    QLabel * slash[2] = { new QLabel( QString( '/' ) ),
                          new QLabel( QString( '/' ) ) };

    editData_Day = new LineEditValidate( QRegExp( "[1-3]{0,1}[1-9]" ) );
    editData_Day->setAlignment( Qt::AlignRight );
    editData_Day->setMaxLength( 2 );
    editData_Month = new LineEditValidate( QRegExp( "[0-1][1-9]" ) );
    editData_Month->setAlignment( Qt::AlignRight );
    editData_Month->setMaxLength( 2 );
    editData_Year = new LineEditValidate( QRegExp( "[1-9][0-9]{3}" ) );
    editData_Year->setAlignment( Qt::AlignRight );
    editData_Year->setMaxLength( 4 );

    QFormLayout * layoutForm = new QFormLayout;
    layoutForm->setHorizontalSpacing( 50 );

    layoutForm->addRow( tr( "Name" ) + ':', editName );
    layoutForm->addRow( tr( "Surname" ) + ':', editSurname );

    QHBoxLayout * layoutNumber = new QHBoxLayout;
    layoutNumber->addWidget( editPrefixNumber );
    layoutNumber->addWidget( editNumber );

    layoutForm->addRow( tr( "Number" ) + ':', layoutNumber );

    QHBoxLayout * layoutData = new QHBoxLayout;
    layoutData->addWidget( editData_Day );
    layoutData->addWidget( slash[0] );
    layoutData->addWidget( editData_Month );
    layoutData->addWidget( slash[1] );
    layoutData->addWidget( editData_Year );

    layoutForm->addRow( tr( "Data" ) + ':', layoutData );

    QWidget * container = new QWidget();
    container->setMaximumWidth( 400 );
    container->setLayout( layoutForm );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( container );

    setLayout( layout );
}


UserEditPage::ModuleID::~ModuleID()
{
    delete editName;
    delete editSurname;
    delete editPrefixNumber;
    delete editNumber;
    delete editData_Day;
    delete editData_Month;
    delete editData_Year;
}


UserEditPage::ModuleSkills::ModuleSkills( QWidget * parent )
                                          : QWidget( parent )
{
    setLayout( new QVBoxLayout );
}


UserEditPage::ModuleSkills::~ModuleSkills()
{
}


QVector<QString> UserEditPage::ModuleSkills::getSkills() const
{
    QVector<QString> skills;

    std::transform( listaSkills.begin(),
                    listaSkills.end(),
                    skills.begin(),
                    [] ( QLineEdit * p ) -> Skill
                    {
                        return p->text();
                    } );

    return skills;
}


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
