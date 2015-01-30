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

    std::transform( listaSkills.begin(),
                    listaSkills.end(),
                    skills.begin(),
                    [] ( QLineEdit * p ) -> Skill
                    {
                        return p->text();
                    } );

    return skills;
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
