#include "moduleexperience.h"

ModuleExperience::ModuleQualifica::ModuleQualifica( QWidget * parent )
                                                    : QWidget( parent )
{
    editExp = new LineEditValidate( QRegExp( "[A-Za-z]*" ) );
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
    delete editExp;
    delete editCompany;
    delete editDurata;
    delete editDescrizione;
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


QVector<Experience> ModuleExperience::getExperiences() const
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


