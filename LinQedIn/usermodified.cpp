#include "usermodified.h"

UserModified::UserModified( QWidget * parent ) : QWidget( parent )
{
    QPushButton * btnReset = new QPushButton( tr( "Reset" ) );
    QPushButton * btnApply = new QPushButton( tr( "Apply" ) );

    UserEditPage * editPage = new UserEditPage();

    QHBoxLayout * layoutButton = new QHBoxLayout;
    layoutButton->setAlignment( Qt::AlignRight );
    layoutButton->addWidget( btnApply );
    layoutButton->addWidget( btnReset );


    QVBoxLayout * layoutBottom = new QVBoxLayout;
    layoutBottom->setAlignment( Qt::AlignBottom );
    layoutBottom->addWidget( new Line() );
    layoutBottom->addLayout( layoutButton );


    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget( editPage );
    layout->addLayout( layoutBottom );

    setLayout( layout );
}


UserModified::~UserModified()
{
}

