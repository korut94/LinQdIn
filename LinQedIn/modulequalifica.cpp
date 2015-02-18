#include "modulequalifica.h"

ModuleQualifica::ModuleQualifica( const Experience & exp,
                                                    QWidget * parent )
                                                    : QWidget( parent )
{
    editExp = new QLineEdit( exp.getWork() );
    editCompany = new QLineEdit( exp.getCompany() );
    editDurata = new QLineEdit( exp.getPeriod() );
    editDescrizione = new QTextEdit( exp.getDescription() );
    QPushButton * btnRemove = new QPushButton( tr( "Remove" ) );
    btnRemove->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    QFormLayout * layout = new QFormLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->setHorizontalSpacing( 30 );
    layout->addRow( tr( "Work" ) + ':', editExp );
    layout->addRow( tr( "Company" ) + ':', editCompany );
    layout->addRow( tr( "Time Period" ) + ':', editDurata );
    layout->addRow( tr( "Description" ) + ':', editDescrizione );
    layout->addWidget( btnRemove );

    setLayout( layout );

    connect( btnRemove,
             SIGNAL( clicked() ),
             this,
             SLOT( remove() ) );
}


ModuleQualifica::~ModuleQualifica()
{
}


bool ModuleQualifica::complete() const
{
    return ( !editCompany->text().isEmpty() &&
             !editDescrizione->toPlainText().isEmpty() &&
             !editDurata->text().isEmpty() &&
             !editExp->text().isEmpty() );
}


Experience ModuleQualifica::getExperience() const
{
    return Experience( editExp->text(),
                       editCompany->text(),
                       editDurata->text(),
                       editDescrizione->toPlainText() );
}


void ModuleQualifica::remove()
{
    emit sendRemove( this );
}


void ModuleQualifica::reset()
{
    editCompany->clear();
    editDescrizione->clear();
    editDurata->clear();
    editExp->clear();
}
