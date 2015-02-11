#include "line.h"

Line::Line( QWidget * parent ) : QLabel( parent )
{
    setFrameStyle( QFrame::HLine | QFrame::Plain );
    setLineWidth( 1 );
}


Line::~Line()
{
}
