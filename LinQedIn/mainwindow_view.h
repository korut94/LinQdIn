#ifndef MAINWINDOW_VIEW_H
#define MAINWINDOW_VIEW_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>

#include "riconoscimenti.h"
#include "tabcontroller.h"

class MainWindow_View : public QWidget
{
    private:
        QTabWidget * tabInterface;

    public:
        MainWindow_View( QWidget * = NULL );
        ~MainWindow_View();

        void addInterface( QWidget *, const QString & );
};

#endif // MAINWINDOW_VIEW_H
