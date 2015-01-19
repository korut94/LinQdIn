#include "useritem.h"

UserItem::UserItem( const Info & info, QWidget * parent ) : QWidget( parent )
{
    setMinimumHeight( 52 );
    setMaximumHeight( 52 );

    QPixmap pixmap( "../LinQedIn/User_48x36.png" );
    QLabel * icon = new QLabel();
    icon->setMaximumWidth( 50 );

    icon->setPixmap( pixmap );

    QLabel * name = new QLabel( "<b>" + info.getNome() + "</b>" );
    //name->setStyleSheet( "QLabel { text-align : center; }" );
    QLabel * surname = new QLabel( "<b>" + info.getCognome() + "</b>" );
    //surname->setStyleSheet( "QLabel { text-align : center; }" );

    QVBoxLayout * layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget( name );
    layoutInfo->addWidget( surname );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( icon );
    layout->addLayout( layoutInfo );

    setLayout( layout );
}


UserItem::~UserItem()
{
}
