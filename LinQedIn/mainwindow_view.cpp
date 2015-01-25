#include "mainwindow_view.h"

MainWindow_View::MainWindow_View( QWidget * parent ) : QWidget( parent )
{
    setMinimumSize( 800, 480 );

    QGroupBox * box = new QGroupBox( "LinQedIn Manager" );

    //AdminInterface_Controller * admin = new AdminInterface_Controller();

    tabInterface = new QTabWidget();
    /*
    tabInterface->addTab( admin->getView(), "Administrator" );
    tabInterface->addTab( btm2, "User" );
    */
    QVBoxLayout * layoutBox = new QVBoxLayout;
    layoutBox->addWidget( tabInterface );

    box->setLayout( layoutBox );

    Riconoscimenti * riconoscimenti = new Riconoscimenti();

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( box );
    layout->addWidget( riconoscimenti );

    setLayout( layout );
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
