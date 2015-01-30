#include "moduleeducation.h"

ModuleEducation::ModuleStudio::ModuleStudio( QWidget * parent )
                                             : QWidget( parent )
{
    editSchool = new LineEditValidate( QRegExp( "[A-Za-z]*" ) );
    editTitle = new QLineEdit();
    editDurata = new QLineEdit();
    editDescrizione = new QTextEdit();

    QFormLayout * layout = new QFormLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->setHorizontalSpacing( 30 );
    layout->addRow( tr( "School" ) + ':', editSchool );
    layout->addRow( tr( "Title" ) + ':', editTitle );
    layout->addRow( tr( "Time Period" ) + ':', editDurata );
    layout->addRow( tr( "Description" ) + ':', editDescrizione );

    setLayout( layout );
}


ModuleEducation::ModuleStudio::~ModuleStudio()
{
    delete editSchool;
    delete editTitle;
    delete editDurata;
    delete editDescrizione;
}


Experience ModuleEducation::ModuleStudio::getEducation() const
{
    return Experience( editSchool->text(),
                       editTitle->text(),
                       editDurata->text(),
                       editDescrizione->toPlainText() );
}


void ModuleEducation::ModuleStudio::reset()
{
    editDescrizione->clear();
    editDurata->clear();
    editSchool->clear();
    editTitle->clear();
}


ModuleEducation::ModuleEducation( QWidget * parent ) : QWidget( parent )
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignBottom );

    setLayout( layout );
}


ModuleEducation::~ModuleEducation()
{

}


QVector<Experience> ModuleEducation::getEducations() const
{
    QVector<Experience> educations;

    std::transform( listaStudio.begin(),
                    listaStudio.end(),
                    educations.begin(),
                    [] ( ModuleStudio * p ) -> Experience
                    {
                        return p->getEducation();
                    } );

    return educations;
}


void ModuleEducation::addEducation()
{
    ModuleStudio * studio = new ModuleStudio();

    listaStudio.push_back( studio );
    layout()->addWidget( studio );
}


void ModuleEducation::reset()
{
    for( QVector<ModuleStudio*>::const_iterator itr = listaStudio.begin();
         itr != listaStudio.end();
         itr++ )
    {
        (*itr)->reset();
    }
}


