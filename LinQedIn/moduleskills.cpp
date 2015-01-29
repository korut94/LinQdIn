#include "moduleskills.h"

ModuleSkills::ModuleSkills( QWidget * parent )
                            : QWidget( parent )
{
    setLayout( new QVBoxLayout );
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
