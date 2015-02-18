#include "moduleskill.h"

ModuleSkill::ModuleSkill( const Skill & skill, QWidget * parent )
                          : QWidget( parent )
{
    editSkill = new QLineEdit( skill.getSkill() );
    QPushButton * btnRemove = new QPushButton( tr( "Remove" ) );

    QHBoxLayout * layout = new QHBoxLayout;

    layout->addWidget( editSkill );
    layout->addWidget( btnRemove );

    setLayout( layout );

    connect( btnRemove,
             SIGNAL( clicked() ),
             this,
             SLOT( remove() ) );
}


ModuleSkill::~ModuleSkill()
{

}


bool ModuleSkill::complete() const
{
    return editSkill->text().isEmpty();
}


Skill ModuleSkill::getSkill() const
{
    return editSkill->text();
}


void ModuleSkill::remove()
{
    emit sendRemove( this );
}


void ModuleSkill::reset()
{
    editSkill->clear();
}
