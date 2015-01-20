#include "admininterface_view.h"

AdminInterface_View::AdminInterface_View( QWidget * parent )
                                          : QWidget( parent )
{
    LabelTools * tools = new LabelTools();
    TableUsers * table = new TableUsers();

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setAlignment( Qt::AlignLeft );
    layout->addWidget( table );
    layout->addWidget( tools );

    setLayout( layout );
}


AdminInterface_View::~AdminInterface_View()
{

}
