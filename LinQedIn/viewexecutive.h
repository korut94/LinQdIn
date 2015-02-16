#ifndef VIEWEXECUTIVE_H
#define VIEWEXECUTIVE_H

#include "viewbusiness.h"

class ViewExecutive : public ViewBase
{
    public slots:
        void loadMainPage( const smartptr_utente & user );

    public:
        ViewExecutive( QWidget * = nullptr );
};

#endif // VIEWEXECUTIVE_H
