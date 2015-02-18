#include "id.h"

ID::ID( const Personal & personal, QWidget * parent ) : QWidget( parent )
{
    QPixmap image( "../LinQedIn/User_150x114.png" );

    QLabel * lblImage = new QLabel();
    lblImage->setPixmap( image );

    QLabel * lblFullname = new QLabel( personal.getNome() +
                                       " " +
                                       personal.getCognome() );
    lblFullname->setStyleSheet( "QLabel{ font-weight: bold; }" );
    QLabel * lblTelephone = new QLabel( tr( "Telephone" ) + ':' );
    QLabel * valTelephone = new QLabel( personal.getNumTelefono() );
    QLabel * lblData = new QLabel( tr( "Data" ) + ':' );
    QLabel * valData = new QLabel( personal.getDate().
                                   toString( "dd MMMM yyyy" ) );
    QLabel * lblJob = new QLabel( tr( "Job" ) + ':' );
    QLabel * valJob = new QLabel( personal.getActualWork() );

    QFormLayout * layoutExtra = new QFormLayout;
    layoutExtra->setHorizontalSpacing( 25 );
    layoutExtra->addRow( lblTelephone, valTelephone );
    layoutExtra->addRow( lblData, valData );
    layoutExtra->addRow( lblJob, valJob );

    QVBoxLayout * layoutInfo = new QVBoxLayout;
    layoutInfo->addWidget( lblFullname );
    layoutInfo->addLayout( layoutExtra );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setAlignment( Qt::AlignLeft );
    layout->addWidget( lblImage );
    layout->addLayout( layoutInfo );

    setLayout( layout );
}


ID::~ID()
{
}
