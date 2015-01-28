#include "id.h"

ID::ID( const LevelAccess::Type & level, QWidget * parent )
                            : QWidget( parent )
{
    QPixmap image( "../LinQedIn/User_150x114.png" );

    QLabel * lblImage = new QLabel();
    lblImage->setPixmap( image );

    QLabel * lblFullname = new QLabel( "Andrea Mantovani" );
    QLabel * lblTelephone = new QLabel( tr( "Telephone" ) + ':' );
    QLabel * valTelephone = new QLabel( "3406936174" );
    QLabel * lblData = new QLabel( tr( "Data" ) + ':' );
    QLabel * valData = new QLabel( "17/09/1994" );
    QLabel * lblJob = new QLabel( tr( "Job" ) + ':' );
    QLabel * valJob = new QLabel( "Student" );

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
