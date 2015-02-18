#include "moduleskills.h"

ModuleSkills::ModuleSkills( QWidget * parent ) : QWidget( parent )
{
    QVBoxLayout * layout = new QVBoxLayout;
    layout->setAlignment( Qt::AlignBottom );

    setLayout( layout );
}


ModuleSkills::~ModuleSkills()
{
}


QVector<Skill> ModuleSkills::getSkills() const
{
    QVector<Skill> skills;

    for( QVector<ModuleSkill*>::const_iterator itr = listaSkills.begin();
         itr != listaSkills.end();
         itr++ )
    {
        skills.push_back( (*itr)->getSkill() );
    }

    return skills;
}


bool ModuleSkills::complete() const
{
    if( listaSkills.size() == 0 ) return true;
    else
    {
        QVector<ModuleSkill *>::const_iterator itr = listaSkills.begin();
        bool complete = true;

        while( itr != listaSkills.end() && complete )
        {
            complete = !( (*itr)->complete() );
            itr++;
        }

        return complete;
    }
}


void ModuleSkills::addSkill( const Skill & skill )
{
    ModuleSkill * editSkill = new ModuleSkill( skill.getSkill() );

    connect( editSkill,
             SIGNAL( sendRemove( ModuleSkill * ) ),
             this,
             SIGNAL( requestRemoveSkill( ModuleSkill * ) ) );

    listaSkills.push_back( editSkill );
    layout()->addWidget( editSkill );
}


void ModuleSkills::removeSkill( ModuleSkill * sk )
{
    QVector<ModuleSkill*>::iterator itr = listaSkills.begin();

    while( *itr != sk ) itr++;
    listaSkills.erase( itr );

    layout()->removeWidget( sk );
    delete sk;
}


void ModuleSkills::reset()
{
    for( QVector<ModuleSkill*>::const_iterator itr = listaSkills.begin();
         itr != listaSkills.end();
         itr++ )
    {
        (*itr)->reset();
    }
}


void ModuleSkills::setContent( const QVector<Skill> & skills )
{
    for( QVector<Skill>::const_iterator itr = skills.begin();
         itr != skills.end();
         itr++ )
    {
        addSkill( *itr );
    }
}
