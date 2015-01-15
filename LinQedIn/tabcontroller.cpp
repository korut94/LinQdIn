#include "tabcontroller.h"

TabController::TabController( QWidget * parent ) : QWidget( parent )
{
    QPushButton * btm1 = new QPushButton( "Push" );
    QPushButton * btm2 = new QPushButton( "Push" );

    QTabWidget * tabs = new QTabWidget();
    tabs->addTab( btm1, "Administrator" );
    tabs->addTab( btm2, "User" );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( tabs );

    setLayout( layout );
}


TabController::~TabController()
{
}
