#include "mainwindow_view.h"

MainWindow_View::MainWindow_View( QWidget * parent ) : QWidget( parent )
{
    setMinimumSize( 800, 480 );

    QGroupBox * box = new QGroupBox( "LinQedIn Manager" );

    tabInterface = new QTabWidget();

    QVBoxLayout * layoutBox = new QVBoxLayout;
    layoutBox->addWidget( tabInterface );

    box->setLayout( layoutBox );

    Riconoscimenti * riconoscimenti = new Riconoscimenti();

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( box );
    layout->addWidget( riconoscimenti );

    setLayout( layout );

    connect( tabInterface,
             SIGNAL( currentChanged( int ) ),
             this,
             SIGNAL( currentInterface( int ) ) );
}


MainWindow_View::~MainWindow_View()
{
    delete tabInterface;
}


void MainWindow_View::addInterface( QWidget * interface,
                                    const QString & name )
{
    tabInterface->addTab( interface, name );
}
