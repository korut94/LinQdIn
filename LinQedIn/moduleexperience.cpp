#include "moduleexperience.h"

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


void ModuleExperience::addExperience( const Experience & exp )
{
    ModuleQualifica * qualifica = new ModuleQualifica( exp );

    connect( qualifica,
             SIGNAL( sendRemove( ModuleQualifica * ) ),
             this,
             SIGNAL( requestRemoveExperience( ModuleQualifica* ) ) );

    listaQualifica.push_back( qualifica );
    layout()->addWidget( qualifica );
}


void ModuleExperience::removeExperience( ModuleQualifica * mod )
{
    QVector<ModuleQualifica*>::iterator itr = listaQualifica.begin();

    while( *itr != mod ) itr++;
    listaQualifica.erase( itr );

    layout()->removeWidget( mod );
    delete mod;
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


void ModuleExperience::setContent( const QVector<Experience> & exp )
{
    for( QVector<Experience>::const_iterator itr = exp.begin();
         itr != exp.end();
         itr++ )
    {
        addExperience( *itr );
    }
}

