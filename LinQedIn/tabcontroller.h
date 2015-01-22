#ifndef TABCONTOLLER_H
#define TABCONTOLLER_H

#include <QHeaderView>
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "admininterface.h"

class TabController : public QWidget
{
    public:
        TabController( QWidget * = NULL );
        ~TabController();
};

#endif //TABCONTOLLER_H
