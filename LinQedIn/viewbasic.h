#ifndef VIEWBASIC_H
#define VIEWBASIC_H

#include "viewbase.h"

class ViewBasic : public ViewBase
{
    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewBasic( QWidget * = nullptr );
};

#endif // VIEWBASIC_H
