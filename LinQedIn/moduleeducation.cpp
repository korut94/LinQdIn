#include "moduleeducation.h"

ModuleEducation::ModuleStudio::ModuleStudio( const Experience & exp,
                                             QWidget * parent )
                                             : QWidget( parent )
{
    editSchool = new LineEditValidate( QRegExp( "[A-Za-z]*" ), exp.getWork() );
    editTitle = new QLineEdit( exp.getCompany() );
    editDurata = new QLineEdit( exp.getPeriod() );
    editDescrizione = new QTextEdit( exp.getDescription() );

    QFormLayout * layout = new QFormLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->setHorizontalSpacing( 30 );
    layout->addRow( tr( "School" ) + ':', editSchool );
    layout->addRow( tr( "Title" ) + ':', editTitle );
    layout->addRow( tr( "Time Period" ) + ':', editDurata );
    layout->addRow( tr( "Description" ) + ':', editDescrizione );

    setLayout( layout );
}


bool ModuleEducation::ModuleStudio::checkError() const
{
    return ( editSchool->text().isEmpty() ||
             editSchool->check() == QValidator::Acceptable );
}


bool ModuleEducation::ModuleStudio::complete() const
{
    return ( !editDescrizione->toPlainText().isEmpty() &&
             !editDurata->text().isEmpty() &&
             !editSchool->text().isEmpty() &&
             !editTitle->text().isEmpty() );
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


ModuleEducation::ModuleEducation( const Info & info,
                                  QWidget * parent ) : QWidget( parent )
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignBottom );

    setLayout( layout );

    const QVector<Experience> & esp = info.getSchoolExperiences();

    for( QVector<Experience>::const_iterator itr = esp.begin();
         itr != esp.end();
         itr++ )
    {
        addEducation( *itr );
    }
}


ModuleEducation::~ModuleEducation()
{

}


bool ModuleEducation::checkError() const
{
    QVector<ModuleStudio *>::const_iterator itr = listaStudio.begin();
    bool check = true;

    while( itr != listaStudio.end() && check )
    {
        check = (*itr)->checkError();
        itr++;
    }

    return check;
}


bool ModuleEducation::complete() const
{
    if( listaStudio.size() == 0 ) return true;
    else
    {
        QVector<ModuleStudio *>::const_iterator itr = listaStudio.begin();
        bool complete = true;

        while( itr != listaStudio.end() && complete )
        {
            complete = (*itr)->complete();
            itr++;
        }

        return complete;
    }
}


QVector<Experience> ModuleEducation::getEducations() const
{
    QVector<Experience> educations;

    for( QVector<ModuleStudio *>::const_iterator itr = listaStudio.begin();
         itr != listaStudio.end();
         itr++ )
    {
        educations.push_back( (*itr)->getEducation() );
    }

    return educations;
}


void ModuleEducation::addEducation( const Experience & exp )
{
    ModuleStudio * studio = new ModuleStudio( exp );

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


