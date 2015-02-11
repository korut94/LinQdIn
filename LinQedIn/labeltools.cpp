#include "labeltools.h"

LabelTools::LabelTools( QWidget * parent ) : QWidget( parent )
{
    QPushButton * add = new QPushButton( tr( "Add" ) );
    QPushButton * remove = new QPushButton( tr( "Remove" ) );
    QPushButton * search = new QPushButton( tr( "Search User" ) );
    QPushButton * all = new QPushButton( tr( "View Users" ) );
    QPushButton * btnSave = new QPushButton( tr( "Save DB" ) );
    QPushButton * btnLoad = new QPushButton( tr( "Load DB" ) );

    QHBoxLayout * layoutModify = new QHBoxLayout;
    QHBoxLayout * layoutDB = new QHBoxLayout;
    QHBoxLayout * layoutSearch = new QHBoxLayout;

    layoutSearch->setAlignment( Qt::AlignLeft );
    layoutSearch->addWidget( search );
    layoutSearch->addWidget( all );

    layoutDB->setAlignment( Qt::AlignCenter );
    layoutDB->addWidget( btnSave );
    layoutDB->addWidget( btnLoad );

    layoutModify->setAlignment( Qt::AlignRight );
    layoutModify->addWidget( add );
    layoutModify->addWidget( remove );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->addLayout( layoutSearch );
    layout->addLayout( layoutDB );
    layout->addLayout( layoutModify );

    setLayout( layout );

    connect( add, SIGNAL( clicked() ), this, SIGNAL( add() ) );
    connect( search, SIGNAL( clicked() ), this, SIGNAL( search() ) );
    connect( all, SIGNAL( clicked() ), this, SIGNAL( viewAllUsers() ) );
    connect( remove, SIGNAL( clicked() ), this, SIGNAL( remove() ) );
    connect( btnSave, SIGNAL( clicked() ), this, SIGNAL( save() ) );
    connect( btnLoad, SIGNAL( clicked() ), this, SIGNAL( load() ) );
}


LabelTools::~LabelTools()
{
}
