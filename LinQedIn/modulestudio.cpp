#include "modulestudio.h"

ModuleStudio::ModuleStudio( const Experience & exp,
                                             QWidget * parent )
                                             : QWidget( parent )
{
    editSchool = new LineEditValidate( QRegExp( "[A-Za-z]*" ), exp.getWork() );
    editTitle = new QLineEdit( exp.getCompany() );
    editDurata = new QLineEdit( exp.getPeriod() );
    editDescrizione = new QTextEdit( exp.getDescription() );
    QPushButton * btnRemove = new QPushButton( tr( "Remove" ) );
    btnRemove->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );


    QFormLayout * layout = new QFormLayout;
    layout->setAlignment( Qt::AlignTop );
    layout->setHorizontalSpacing( 30 );
    layout->addRow( tr( "School" ) + ':', editSchool );
    layout->addRow( tr( "Title" ) + ':', editTitle );
    layout->addRow( tr( "Time Period" ) + ':', editDurata );
    layout->addRow( tr( "Description" ) + ':', editDescrizione );
    layout->addWidget( btnRemove );

    setLayout( layout );

    connect( btnRemove,
             SIGNAL( clicked() ),
             this,
             SLOT( remove() ) );
}


bool ModuleStudio::checkError() const
{
    return ( editSchool->text().isEmpty() ||
             editSchool->check() == QValidator::Acceptable );
}


bool ModuleStudio::complete() const
{
    return ( !editDescrizione->toPlainText().isEmpty() &&
             !editDurata->text().isEmpty() &&
             !editSchool->text().isEmpty() &&
             !editTitle->text().isEmpty() );
}


ModuleStudio::~ModuleStudio()
{
    delete editSchool;
    delete editTitle;
    delete editDurata;
    delete editDescrizione;
}


Experience ModuleStudio::getEducation() const
{
    return Experience( editSchool->text(),
                       editTitle->text(),
                       editDurata->text(),
                       editDescrizione->toPlainText() );
}


void ModuleStudio::remove()
{
    emit sendRemove( this );
}


void ModuleStudio::reset()
{
    editDescrizione->clear();
    editDurata->clear();
    editSchool->clear();
    editTitle->clear();
}

