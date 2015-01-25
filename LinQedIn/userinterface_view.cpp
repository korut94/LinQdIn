#include "userinterface_view.h"

UserInterface_View::UserInterface_View( QWidget * parent ) : QWidget( parent )
{
    QPushButton * button = new QPushButton( "Push" );
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( button );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{

}
