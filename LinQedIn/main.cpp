#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#include "utente.h"

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );

    MainWindow w;
    w.show();

    Info info1( "Andrea",
                "Mantovani",
                "3406936174",
                "17/09/1994");

    SmartClass::smartptr utente = new Utente( "korut94", "36633663", info1 );
    SmartClass::smartptr utente1 = new Utente( "Ciccio", "Nano", info1 );

    utente = utente1;

    return a.exec();
}
