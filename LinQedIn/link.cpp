#include "link.h"

Link::Link( const QString & url, const QString & note, QWidget * parent )
            : QWidget( parent )
{
    QLabel * preLink = new QLabel( note );
    preLink->setAlignment( Qt::AlignRight );

    QLabel * link = new QLabel( url );
    link->setMaximumWidth( link->fontMetrics()
                           .boundingRect( link->text() ).width() );
    link->setAlignment( Qt::AlignRight );

    link->setTextInteractionFlags( Qt::LinksAccessibleByMouse ) ;
    link->setOpenExternalLinks( true );
    link->setText( "<a href=" + url + '>' + url + "</a>" );

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget( preLink );
    layout->addWidget( link );

    setLayout( layout );
}


Link::~Link()
{
}
