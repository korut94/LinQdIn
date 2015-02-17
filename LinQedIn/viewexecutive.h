#ifndef VIEWEXECUTIVE_H
#define VIEWEXECUTIVE_H

#include "viewbusiness.h"

class ViewExecutive : public ViewOther
{
    Q_OBJECT

    public slots:
        void loadMainPage( const smartptr_utente & user );

    public:
        ViewExecutive( QWidget * = nullptr );
        ~ViewExecutive();
};

#endif // VIEWEXECUTIVE_H
