#include "moduleid.h"

const int ModuleID::startYear = 1910;

QStringList ModuleID::insertNumDay()
{
    QStringList list;

    for( int day = 1; day < 32; day ++ )
    {
        list.push_back( QString::number( day ) );
    }

    return list;
}


QStringList ModuleID::insertNameMonth()
{
    QStringList list;

    list.push_back( tr( "January" ) );
    list.push_back( tr( "February" ) );
    list.push_back( tr( "March" ) );
    list.push_back( tr( "April" ) );
    list.push_back( tr( "May" ) );
    list.push_back( tr( "June" ) );
    list.push_back( tr( "July" ) );
    list.push_back( tr( "August" ) );
    list.push_back( tr( "September" ) );
    list.push_back( tr( "October" ) );
    list.push_back( tr( "November" ) );
    list.push_back( tr( "December" ) );

    return list;
}


QStringList ModuleID::insertNumYear()
{
    QStringList list;

    for( int year = startYear; year < QDate::currentDate().year() + 1; year++ )
    {
        list.push_back( QString::number( year ) );
    }

    return list;
}


ModuleID::ModuleID( QWidget * parent ) : QWidget( parent )
{
    editName = new LineEditValidate( QRegExp( "[A-Z][a-z]*" ) );

    editSurname = new LineEditValidate( QRegExp( "[A-Z][a-z]*" ) );

    editPrefixNumber = new LineEditValidate( QRegExp( "[0-9]*" ) );
    editPrefixNumber->setFixedWidth( 40 );
    editPrefixNumber->setMaxLength( 3 );
    editNumber = new LineEditValidate( QRegExp( "[0-9]*" ) );
    editDate_Day = new QComboBox();
    editDate_Day->setStyleSheet( "combobox-popup: 0;" );
    editDate_Day->addItems( insertNumDay() );
    editDate_Month = new QComboBox();
    editDate_Month->setStyleSheet( "combobox-popup: 0;" );
    editDate_Month->addItems( insertNameMonth() );
    editDate_Year = new QComboBox();
    editDate_Year->setStyleSheet( "combobox-popup: 0;" );
    editDate_Year->addItems( insertNumYear() );
    editActualWork = new QLineEdit();

    QFormLayout * layoutForm = new QFormLayout;
    layoutForm->setHorizontalSpacing( 50 );

    layoutForm->addRow( tr( "Name" ) + ':', editName );
    layoutForm->addRow( tr( "Surname" ) + ':', editSurname );

    QHBoxLayout * layoutNumber = new QHBoxLayout;
    layoutNumber->addWidget( new QLabel( "+" ) );
    layoutNumber->addWidget( editPrefixNumber );
    layoutNumber->addWidget( editNumber );

    layoutForm->addRow( tr( "Number" ) + ':', layoutNumber );

    QHBoxLayout * layoutDate = new QHBoxLayout;
    layoutDate->addWidget( editDate_Day );
    layoutDate->addWidget( editDate_Month );
    layoutDate->addWidget( editDate_Year );

    layoutForm->addRow( tr( "Date of birth" ) + ':', layoutDate );
    layoutForm->addRow( tr( "Actual work" ) + ':', editActualWork );

    QWidget * container = new QWidget();
    container->setMaximumWidth( 400 );
    container->setLayout( layoutForm );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( container );

    setLayout( layout );
}


ModuleID::~ModuleID()
{
}


bool ModuleID::checkError() const
{
    return(
                ( editName->text().isEmpty() ||
                  editName->check() == QValidator::Acceptable ) &&
                ( editSurname->text().isEmpty() ||
                  editSurname->check() == QValidator::Acceptable ) &&
                ( editPrefixNumber->text().isEmpty() ||
                  editPrefixNumber->check() == QValidator::Acceptable ) &&
                ( editNumber->text().isEmpty() ||
                  editNumber->check() == QValidator::Acceptable ) &&
                ( QDate::isValid( startYear + editDate_Year->currentIndex(),
                                  editDate_Month->currentIndex() + 1,
                                  editDate_Day->currentIndex() + 1 )  )
           );
}


bool ModuleID::complete() const
{
    return ( !editName->text().isEmpty() &&
             !editNumber->text().isEmpty() &&
             !editPrefixNumber->text().isEmpty() &&
             !editSurname->text().isEmpty() &&
             !editActualWork->text().isEmpty() );
}


Personal ModuleID::getDatePersonal() const
{
    Personal risult;

    risult.setNome( editName->text() );
    risult.setCognome( editSurname->text() );

    QString fullNumber = '+' +
                         editPrefixNumber->text() +
                         '-' +
                         editNumber->text();

    risult.setNumTelefono( fullNumber );

    risult.setDate( QDate( startYear + editDate_Year->currentIndex(),
                           editDate_Month->currentIndex() + 1,
                           editDate_Day->currentIndex() + 1 ) );

    risult.setActualWork( editActualWork->text() );

    return risult;
}


void ModuleID::reset()
{
    editDate_Day->setCurrentIndex( 0 );
    editDate_Month->setCurrentIndex( 0 );
    editDate_Year->setCurrentIndex( 0 );
    editName->clear();
    editNumber->clear();
    editPrefixNumber->clear();
    editSurname->clear();
    editActualWork->clear();
}


void ModuleID::setContent( const Personal & per )
{
    editName->setText( per.getNome() );
    editSurname->setText( per.getCognome() );

    QStringList fullnumber = per.getNumTelefono().split( "-" );

    //Elimino il segno + sul prefisso nazionale
    editPrefixNumber->setText( fullnumber[0].remove( 0, 1 ) );
    editNumber->setText( fullnumber.at( 1 ) );

    QDate date = per.getDate();

    editDate_Day->setCurrentIndex( date.day() - 1 );
    editDate_Month->setCurrentIndex( date.month() - 1 );
    editDate_Year->setCurrentIndex( date.year() - startYear );
    editActualWork->setText( per.getActualWork() );
}

