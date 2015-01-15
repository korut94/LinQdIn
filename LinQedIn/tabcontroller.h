#ifndef TABCONTOLLER_H
#define TABCONTOLLER_H

#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

class TabController : public QWidget
{
    public:
        TabController( QWidget * = NULL );
        ~TabController();
};

#endif // TABCONTOLLER_H
