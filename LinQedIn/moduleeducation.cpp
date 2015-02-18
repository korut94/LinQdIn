#include "moduleeducation.h"

ModuleEducation::ModuleEducation( QWidget * parent ) : QWidget( parent )
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignBottom );

    setLayout( layout );


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

    connect( studio,
             SIGNAL( sendRemove( ModuleStudio * ) ),
             this,
             SIGNAL( requestRemoveStudio( ModuleStudio * ) ) );

    listaStudio.push_back( studio );
    layout()->addWidget( studio );
}


void ModuleEducation::removeStudio( ModuleStudio * st )
{
    QVector<ModuleStudio*>::iterator itr = listaStudio.begin();

    while( *itr != st ) itr++;
    listaStudio.erase( itr );

    layout()->removeWidget( st );
    delete st;
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


void ModuleEducation::setContent( const QVector<Experience> & edu )
{
    for( QVector<Experience>::const_iterator itr = edu.begin();
         itr != edu.end();
         itr++ )
    {
        addEducation( *itr );
    }
}

