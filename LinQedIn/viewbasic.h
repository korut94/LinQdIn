#ifndef VIEWBASIC_H
#define VIEWBASIC_H

#include "viewother.h"

class ViewBasic : public ViewOther
{
    Q_OBJECT

    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewBasic( QWidget * = nullptr );
        ~ViewBasic();
};

#endif // VIEWBASIC_H
