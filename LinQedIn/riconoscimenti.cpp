#include "riconoscimenti.h"

Riconoscimenti::Riconoscimenti( QWidget * parent ) : QWidget( parent )
{
    QLabel * autore =
        new QLabel( "GUI and project created by Andrea Mantovani" );

    Link * link = new Link( "https://github.com/korut94/LinQedIn",
                            "Source code link: " );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( autore );
    layout->addWidget( link );

    setLayout( layout );
}


Riconoscimenti::~Riconoscimenti()
{
}
