#include "viewbusiness.h"

ViewBusiness::ViewBusiness( QWidget * parent ) : ViewBase( parent )
{
}


void ViewBusiness::loadMainPage( const smartptr_utente & user )
{
    ViewBasic * basic = new ViewBasic();
    basic->loadMainPage( user );
    basic->layout()->setMargin( 0 );

    ViewExperience * experience = new ViewExperience( user->getInfo() );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->setAlignment( Qt::AlignTop );
    layout->addWidget( basic );
    layout->addWidget( experience );

    setLayout( layout );
}
