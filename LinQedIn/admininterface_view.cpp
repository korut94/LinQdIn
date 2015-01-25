#include "admininterface_view.h"

void AdminInterface_View::setFrameUtility( QWidget * window )
{
    utility->setWidget( window );
}


AdminInterface_View::AdminInterface_View( QWidget * parent )
                                          : QWidget( parent ),
                                            utility( new QScrollArea() )
{
    utility->setWidgetResizable( true );

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
             SIGNAL( add() ),
             this,
             SIGNAL( requestToAddUser() ) );

    connect( tools,
             SIGNAL( search() ),
             this,
             SIGNAL( requestToSearchUsers() ) );
}


AdminInterface_View::~AdminInterface_View()
{

}
