#include "mainwindow_view.h"

MainWindow_View::MainWindow_View( QWidget * parent ) : QWidget( parent )
{
    setMinimumSize( 640, 480 );

    QGroupBox * box = new QGroupBox( "LinQedIn Manager" );

    TabController * controller = new TabController();

    QVBoxLayout * layoutBox = new QVBoxLayout;
    layoutBox->addWidget( controller );

    box->setLayout( layoutBox );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( box );

    setLayout( layout );
}


MainWindow_View::~MainWindow_View()
{
}
