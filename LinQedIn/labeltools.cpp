#include "labeltools.h"

LabelTools::LabelTools( QWidget * parent ) : QWidget( parent )
{
    QPushButton * add = new QPushButton( tr( "Add" ) );
    QPushButton * remove = new QPushButton( tr( "Remove" ) );
    QPushButton * search = new QPushButton( tr( "Query" ) );

    QHBoxLayout * layoutModify = new QHBoxLayout;
    QHBoxLayout * layoutSearch = new QHBoxLayout;

    layoutSearch->setAlignment( Qt::AlignLeft );
    layoutSearch->addWidget( search );

    layoutModify->setAlignment( Qt::AlignRight );
    layoutModify->addWidget( add );
    layoutModify->addWidget( remove );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->setContentsMargins( 0, 0, 0, 0 );
    layout->addLayout( layoutSearch );
    layout->addLayout( layoutModify );

    setLayout( layout );

    connect( search, SIGNAL( clicked() ), this, SIGNAL( search() ) );
}


LabelTools::~LabelTools()
{
}
