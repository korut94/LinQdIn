#ifndef ADMININTERFACE_VIEW_H
#define ADMININTERFACE_VIEW_H

#include <QTableWidget>
#include <QHBoxLayout>
#include <QWidget>

#include "tableusers.h"

class AdminInterface_View : public QWidget
{
    public:
        AdminInterface_View( QWidget * = NULL );
        ~AdminInterface_View();
};

#endif // ADMININTERFACE_VIEW_H
