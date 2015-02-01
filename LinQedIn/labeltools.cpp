#include "labeltools.h"

LabelTools::LabelTools( QWidget * parent ) : QWidget( parent )
{
    QPushButton * add = new QPushButton( tr( "Add" ) );
    QPushButton * remove = new QPushButton( tr( "Remove" ) );
    QPushButton * search = new QPushButton( tr( "Search User" ) );
    QPushButton * all = new QPushButton( tr( "View Users" ) );

    QHBoxLayout * layoutModify = new QHBoxLayout;
    QHBoxLayout * layoutSearch = new QHBoxLayout;

    layoutSearch->setAlignment( Qt::AlignLeft );
    layoutSearch->addWidget( search );
    layoutSearch->addWidget( all );

    layoutModify->setAlignment( Qt::AlignRight );
    layoutModify->addWidget( add );
    layoutModify->addWidget( remove );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->addLayout( layoutSearch );
    layout->addLayout( layoutModify );

    setLayout( layout );

    connect( add, SIGNAL( clicked() ), this, SIGNAL( add() ) );
    connect( search, SIGNAL( clicked() ), this, SIGNAL( search() ) );
    connect( all, SIGNAL( clicked() ), this, SIGNAL( viewAllUsers() ) );
}


LabelTools::~LabelTools()
{
}
