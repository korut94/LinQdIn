#include "labeltools.h"

LabelTools::LabelTools( QWidget * parent ) : QLabel( "Prova", parent )
{
    setFrameStyle( QFrame::StyledPanel );
    setLineWidth( 2 );
}


LabelTools::~LabelTools()
{
}
