#include "tableusers.h"

TableUsers::UserItem::UserItem( const Info & info, QWidget * parent )
                                : QWidget( parent )
{
    setFixedHeight( 80 );

    QPixmap pixmap( "../LinQedIn/User_48x36.png" );
    QLabel * icon = new QLabel();

    icon->setPixmap( pixmap );
    icon->setMaximumWidth( 50 );

    Personal personal = info.getPersonal();

    QLabel * fullname = new QLabel( "<b>" + personal.getNome() +
                                    " " + personal.getCognome() + "</b>" );
    fullname->setStyleSheet( "QLabel{ font: 10pt; }" );

    QLabel * telephone = new QLabel( "Tel: " + personal.getNumTelefono() );
    telephone->setStyleSheet( "QLabel{ font: 8pt; }" );

    QLabel * data = new QLabel( "Data: " +
                                personal.getDate().toString( "dd MMMM yyyy" ) );
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
