#include "moduleaccout.h"

ModuleAccout::ModuleAccout( QWidget * parent ) : QWidget( parent )
{
    account = new QComboBox();
    account->addItem( tr( "Basic" ) );
    account->addItem( tr( "Business" ) );
    account->addItem( tr( "Executive" ) );
    account->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Fixed );

    QFormLayout * layout = new QFormLayout;
    layout->setHorizontalSpacing( 20 );
    layout->addRow( tr( "Account" ) + ':', account );

    setLayout( layout );
}


ModuleAccout::~ModuleAccout()
{
    delete account;
}


void ModuleAccout::reset()
{
    account->setCurrentIndex( 0 );
}
