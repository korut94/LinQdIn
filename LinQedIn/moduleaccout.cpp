#include "moduleaccout.h"

ModuleAccout::ModuleAccout( const smartptr_utente & user,
                            QWidget * parent ) : QWidget( parent )
{
    account = new QComboBox();
    account->addItem( tr( "Basic" ) );
    account->addItem( tr( "Business" ) );
    account->addItem( tr( "Executive" ) );
    account->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Fixed );

    if( user != nullptr )
        account->setCurrentIndex( fromLevelToIndex( user->typeAccount() ) );

    QFormLayout * layout = new QFormLayout;
    layout->setHorizontalSpacing( 20 );
    layout->addRow( tr( "Account" ) + ':', account );

    setLayout( layout );
}


ModuleAccout::~ModuleAccout()
{
    delete account;
}


int ModuleAccout::fromLevelToIndex( LevelAccess::Type level ) const
{
    switch( level )
    {
        case LevelAccess::Basic : return 0;
        case LevelAccess::Business : return 1;
        case LevelAccess::Executive : return 2;

        default : return 0;
    }
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
