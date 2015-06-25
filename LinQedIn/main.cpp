#include <iostream>
#include <QApplication>
#include <QWidget>


#include "mainwindow.h"

int main(int argc, char *argv[] )
{
    QApplication a( argc, argv );

    std::cout << "Hello, World!" << std::end;

    MainWindow w;

    return a.exec();
}
