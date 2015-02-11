#ifndef MAINWINDOW_VIEW_H
#define MAINWINDOW_VIEW_H

#include <QGroupBox>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

#include "riconoscimenti.h"

class MainWindow_View : public QWidget
{
    Q_OBJECT

    private:
        QTabWidget * tabInterface;

    signals:
        void currentInterface( int ) const;

    public:
        MainWindow_View( QWidget * = NULL );
        ~MainWindow_View();

        void addInterface( QWidget *, const QString & );
};

#endif // MAINWINDOW_VIEW_H
