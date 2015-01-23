#include "admininterface_view.h"

void AdminInterface_View::setFrameUtility( UtilityFrame * window )
{
    utility->setWidget( window );

    //Bisogna fare downcasting??
}


AdminInterface_View::AdminInterface_View( QWidget * parent )
                                          : QWidget( parent ),
                                            utility( new QScrollArea() )
{
    LabelTools * tools = new LabelTools();
    TableUsers * table = new TableUsers();

    QHBoxLayout * layoutAdmin = new QHBoxLayout;
    layoutAdmin->setAlignment( Qt::AlignLeft );
    layoutAdmin->addWidget( table );
    layoutAdmin->addWidget( utility );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( tools );
    layout->addLayout( layoutAdmin );

    setLayout( layout );

    connect( tools,
             SIGNAL( search() ),
             this,
             SIGNAL( requestToSearchUsers() ) );
}


AdminInterface_View::~AdminInterface_View()
{

}
