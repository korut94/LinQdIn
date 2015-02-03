#include "moduleaccout.h"

ModuleAccout::ModuleAccout( const smartptr_utente & user,
                            QWidget * parent ) : QWidget( parent )
{
    account = new QComboBox();
    account->addItem( tr( "Basic" ) );
    account->addItem( tr( "Business" ) );
    account->addItem( tr( "Executive" ) );
    account->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Fixed );

    if( user != nullptr ) account->setCurrentIndex( user->typeAccount() - 1 );

    QFormLayout * layout = new QFormLayout;
    layout->setHorizontalSpacing( 20 );
    layout->addRow( tr( "Account" ) + ':', account );

    setLayout( layout );
}


ModuleAccout::~ModuleAccout()
{
    delete account;
}


LevelAccess::Type ModuleAccout::getTypeAccount() const
{
    switch( account->currentIndex() )
    {
        case 0: return LevelAccess::Basic;
        case 1: return LevelAccess::Business;
        case 2: return LevelAccess::Executive;

        default: return LevelAccess::Basic;
    }
}


void ModuleAccout::reset()
{
    account->setCurrentIndex( 0 );
}
