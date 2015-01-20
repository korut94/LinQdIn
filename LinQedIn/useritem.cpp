#include "useritem.h"

UserItem::UserItem( const Info & info, QWidget * parent ) : QWidget( parent )
{
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


UserItem::~UserItem()
{
}
