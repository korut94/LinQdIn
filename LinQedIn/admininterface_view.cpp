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
    TableUsers * table = new TableUsers( tr( "Users" ) );
    table->setSizePolicy( QSizePolicy::Maximum, QSizePolicy::Minimum );


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

    connect( this,
             SIGNAL( updateTable( const QVector<smartptr_utente> &) ),
             table,
             SLOT( setItems( const QVector<smartptr_utente> & ) ) );

    connect( tools,
             SIGNAL( viewAllUsers() ),
             this,
             SIGNAL( requestToViewUsers() ) );

    connect( table,
             SIGNAL( selectUser( const QString &) ),
             this,
             SIGNAL( requestToViewUser(const QString & ) ) );

    connect( tools,
             SIGNAL( remove() ),
             this,
             SIGNAL( requestToRemoveUser() ) );
}


AdminInterface_View::~AdminInterface_View()
{
}
