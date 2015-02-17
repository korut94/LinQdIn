#ifndef VIEWBUSINESS_H
#define VIEWBUSINESS_H

#include "viewbasic.h"

class ViewBusiness : public ViewOther
{    
    Q_OBJECT

    public slots:
        void loadMainPage( const smartptr_utente & );

    public:
        ViewBusiness( QWidget * = nullptr );
        ~ViewBusiness();
};

#endif // VIEWBUSINESS_H
