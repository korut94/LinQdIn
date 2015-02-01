#include "moduleskills.h"

ModuleSkills::ModuleSkills( QWidget * parent )
                            : QWidget( parent )
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

    for( QVector<QLineEdit*>::const_iterator itr = listaSkills.begin();
         itr != listaSkills.end();
         itr++ )
    {
        skills.push_back( (*itr)->text() );
    }

    return skills;
}


bool ModuleSkills::complete() const
{
    if( listaSkills.size() == 0 ) return true;
    else
    {
        QVector<QLineEdit *>::const_iterator itr = listaSkills.begin();
        bool complete = true;

        while( itr != listaSkills.end() && complete )
        {
            complete = !( (*itr)->text().isEmpty() );
            itr++;
        }

        return complete;
    }
}


void ModuleSkills::addSkill()
{
    QLineEdit * skill = new QLineEdit();

    listaSkills.push_back( skill );
    layout()->addWidget( skill );
}


void ModuleSkills::reset()
{
    for( QVector<QLineEdit*>::const_iterator itr = listaSkills.begin();
         itr != listaSkills.end();
         itr++ )
    {
        (*itr)->clear();
    }
}
