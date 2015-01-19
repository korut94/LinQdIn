#include "tabcontroller.h"

TabController::TabController( QWidget * parent ) : QWidget( parent )
{
    AdminInterface * admin = new AdminInterface();

    QPushButton * btm2 = new QPushButton( "Push" );

    QTabWidget * tabs = new QTabWidget();
    tabs->addTab( admin->getView(), "Administrator" );
    tabs->addTab( btm2, "User" );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( tabs );

    setLayout( layout );
}


TabController::~TabController()
{
}
