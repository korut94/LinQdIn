#include "viewbase.h"

void ViewBase::myFriend( bool state )
{
    emit topSetFriend( state );
}


ViewBase::ViewBase( QWidget * parent ) : QWidget( parent )
{
}


ViewBase::~ViewBase()
{
}
