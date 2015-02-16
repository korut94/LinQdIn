#ifndef VIEWBUSINESS_H
#define VIEWBUSINESS_H

#include "viewbasic.h"

class ViewBusiness : public ViewBase
{
    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewBusiness( QWidget * = nullptr );
};

#endif // VIEWBUSINESS_H
