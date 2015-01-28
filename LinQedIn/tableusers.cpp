#include "tableusers.h"

TableUsers::UserItem::UserItem( const Info & info, QWidget * parent )
                                : QWidget( parent )
{
    setFixedHeight( 70 );

    QPixmap pixmap( "../LinQedIn/User_48x36.png" );
    QLabel * icon = new QLabel();

    icon->setPixmap( pixmap );
    icon->setMaximumWidth( 50 );

    QLabel * fullname = new QLabel( "<b>" + info.getNome() +
                                    " " + info.getCognome() + "</b>" );
    fullname->setStyleSheet( "QLabel{ font: 10pt; }" );

    QLabel * telephone = new QLabel( "Tel: " + info.getNumTelefono() );
    telephone->setStyleSheet( "QLabel{ font: 8pt; }" );

    QLabel * data = new QLabel( "Data: " + info.getData() );
    data->setStyleSheet( "QLabel{ font: 8pt; }" );

    QVBoxLayout * layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget( fullname );
    layoutInfo->addWidget( telephone );
    layoutInfo->addWidget( data );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( icon );
    layout->addLayout( layoutInfo );

    setLayout( layout );
}


TableUsers::UserItem::~UserItem()
{
}


TableUsers::TableUsers( const QString & title, QWidget * parent )
                        : QWidget( parent )
{
    setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );
    setMaximumWidth( 300 );

    QScrollArea * areaTable = new QScrollArea;
    areaTable->setWidgetResizable( true );

    listUsers = new QVBoxLayout;
    //Aggiunta degli utenti dall'alto verso il basso
    listUsers->setAlignment( Qt::AlignTop );
    listUsers->setContentsMargins( 0, 0, 0, 0 );

    QLabel * lblTitle = new QLabel( title );
    lblTitle->setAlignment( Qt::AlignCenter );
    lblTitle->setFrameStyle( QFrame::StyledPanel | QFrame::Plain );

    listUsers->addWidget( lblTitle );
    areaTable->setLayout( listUsers );

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( areaTable );
    layout->setContentsMargins( 0, 0, 0, 0 );

    setLayout( layout );
}


void TableUsers::addItem( const Info & info )
{
    listUsers->addWidget( new UserItem( info ) );
}


TableUsers::~TableUsers()
{
    delete listUsers;
}
