#include "useritem.h"

void UserItem::mousePressEvent( QMouseEvent * event )
{
    emit selectThis( username );
}


UserItem::UserItem( const smartptr_utente & user, QWidget * parent )
                    : username( user->getUsername() ),
                      QWidget( parent )
{
    setFixedHeight( 80 );

    QPixmap pixmap( "../LinQedIn/User_48x36.png" );
    QLabel * icon = new QLabel();

    icon->setPixmap( pixmap );
    icon->setMaximumWidth( 50 );

    Personal personal = user->getInfo().getPersonal();


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


UserItem::~UserItem()
{
}
