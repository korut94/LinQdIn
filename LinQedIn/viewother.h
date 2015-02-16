#ifndef VIEWOTHER_H
#define VIEWOTHER_H

#include "viewbase.h"

class ViewOther : public ViewBase
{
    Q_OBJECT

    signals:
        void topSetFriend( bool ) const;

    public slots:
        void myFriend( bool );

    public:
        ViewOther( QWidget * = nullptr );
        ~ViewOther();
};

#endif // VIEWOTHER_H
