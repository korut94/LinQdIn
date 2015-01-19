#include "admininterface_view.h"

AdminInterface_View::AdminInterface_View( QWidget * parent )
                                          : QWidget( parent )
{
    TableUsers * table = new TableUsers();

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( table );

    setLayout( layout );
}


AdminInterface_View::~AdminInterface_View()
{

}
