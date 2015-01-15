#ifndef MAINWINDOW_VIEW_H
#define MAINWINDOW_VIEW_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>

#include "tabcontroller.h"

class MainWindow_View : public QWidget
{
    public:
        MainWindow_View( QWidget * = NULL );
        ~MainWindow_View();
};

#endif // MAINWINDOW_VIEW_H
