#include "link.h"

Link::Link( const QString & url, const QString & note, QWidget * parent )
            : QWidget( parent )
{
    QLabel * link = new QLabel( note +
                                "<a href=" + url + '>' + url + "</a>" );
    link->setAlignment( Qt::AlignRight );

    link->setTextInteractionFlags( Qt::LinksAccessibleByMouse ) ;
    link->setOpenExternalLinks( true );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( link );
    layout->setContentsMargins( 0, 0, 0, 0 );

    setLayout( layout );
}


Link::~Link()
{
}
