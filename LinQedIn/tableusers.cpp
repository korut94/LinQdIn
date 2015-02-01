#include "tableusers.h"

void TableUsers::setItems( const QVector<Info> & users )
{
    QWidget * listUsers = new QWidget();
    QVBoxLayout * layoutList = new QVBoxLayout();
    layoutList->setAlignment( Qt::AlignTop );

    for( QVector<Info>::const_iterator itr = users.begin();
         itr != users.end();
         itr++ )
    layoutList->addWidget( new UserItem( *itr ) );

    listUsers->setLayout( layoutList );
    areaTable->setWidget( listUsers );
}


TableUsers::TableUsers( const QString & title, QWidget * parent )
                        : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );
    setMaximumWidth( 300 );

    areaTable = new QScrollArea;
    areaTable->setWidgetResizable( true );

    QLabel * lblTitle = new QLabel( title );
    lblTitle->setAlignment( Qt::AlignCenter );
    lblTitle->setFrameStyle( QFrame::StyledPanel | QFrame::Plain );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( lblTitle );
    layout->addWidget( areaTable );
    layout->setContentsMargins( 0, 0, 0, 0 );

    setLayout( layout );
}


TableUsers::~TableUsers()
{
}
