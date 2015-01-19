#include "useritem.h"

UserItem::UserItem( const Info & info, QWidget * parent ) : QWidget( parent )
{
    QPixmap pixmap( "../LinQedIn/User_48x36.png" );
    QLabel * icon = new QLabel();

    icon->setPixmap( pixmap );
    icon->setMaximumWidth( 50 );

    QLabel * name = new QLabel( "<b>" + info.getNome() + "</b>" );
    QLabel * surname = new QLabel( "<b>" + info.getCognome() + "</b>" );

    QVBoxLayout * layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget( name );
    layoutInfo->addWidget( surname );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( icon );
    layout->addLayout( layoutInfo );

    setMinimumWidth( 182 );
    setLayout( layout );
}


UserItem::~UserItem()
{
}
