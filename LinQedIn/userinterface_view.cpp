#include "userinterface_view.h"

UserInterface_View::UserInterface_View( LevelAccess l, QWidget * parent )
                                        : level( l ),
                                          QWidget( parent )
{
    QPushButton * button = new QPushButton( "Push" );
    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( button );

    setLayout( layout );
}


UserInterface_View::~UserInterface_View()
{

}
