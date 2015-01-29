#include "moduleexperience.h"

ModuleExperience::ModuleQualifica::
                  ModuleQualifica( QWidget * parent ) : QWidget( parent )
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


ModuleExperience::ModuleExperience( QWidget * parent ) : QWidget( parent )
{
    setLayout( new QVBoxLayout );
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
