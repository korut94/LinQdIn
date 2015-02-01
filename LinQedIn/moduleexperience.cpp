#include "moduleexperience.h"

ModuleExperience::ModuleQualifica::ModuleQualifica( QWidget * parent )
                                                    : QWidget( parent )
{
    editExp = new QLineEdit();
    editCompany = new QLineEdit();
    editDurata = new QLineEdit();
    editDescrizione = new QTextEdit();

    QFormLayout * layout = new QFormLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->setHorizontalSpacing( 30 );
    layout->addRow( tr( "Work" ) + ':', editExp );
    layout->addRow( tr( "Company" ) + ':', editCompany );
    layout->addRow( tr( "Time Period" ) + ':', editDurata );
    layout->addRow( tr( "Description" ) + ':', editDescrizione );

    setLayout( layout );
}


ModuleExperience::ModuleQualifica::~ModuleQualifica()
{
}


bool ModuleExperience::ModuleQualifica::complete() const
{
    return ( !editCompany->text().isEmpty() &&
             !editDescrizione->toPlainText().isEmpty() &&
             !editDurata->text().isEmpty() &&
             !editExp->text().isEmpty() );
}


Experience ModuleExperience::ModuleQualifica::getExperience() const
{
    return Experience( editExp->text(),
                       editCompany->text(),
                       editDurata->text(),
                       editDescrizione->toPlainText() );
}


void ModuleExperience::ModuleQualifica::reset()
{
    editCompany->clear();
    editDescrizione->clear();
    editDurata->clear();
    editExp->clear();
}


ModuleExperience::ModuleExperience( QWidget * parent ) : QWidget( parent )
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignBottom );

    setLayout( layout );
}


ModuleExperience::~ModuleExperience()
{

}


bool ModuleExperience::complete() const
{
    if( listaQualifica.size() == 0 ) return true;
    else
    {
        QVector<ModuleQualifica *>::const_iterator
                                    itr = listaQualifica.begin();
        bool complete = true;

        while( itr != listaQualifica.end() && complete )
        {
            complete = (*itr)->complete();
            itr++;
        }

        return complete;
    }
}


QVector<Experience> ModuleExperience::getExperiences() const
{
    QVector<Experience> experiences;

    for( QVector<ModuleQualifica *>::const_iterator itr =
                                                    listaQualifica.begin();
         itr != listaQualifica.end();
         itr++ )
    {
        experiences.push_back( (*itr)->getExperience() );
    }

    return experiences;
}


void ModuleExperience::addExperience()
{
    ModuleQualifica * qualifica = new ModuleQualifica();

    listaQualifica.push_back( qualifica );
    layout()->addWidget( qualifica );
}


void ModuleExperience::reset()
{
    for( QVector<ModuleQualifica*>::const_iterator itr
                                    = listaQualifica.begin();
         itr != listaQualifica.end();
         itr++ )
    {
        (*itr)->reset();
    }
}


