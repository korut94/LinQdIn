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

    sptr_utente utente = new Utente( "korut94", "36633663", info1 );
    sptr_utente utente1 = new Utente( "Ciccio", "Nano", info1 );

    utente = utente1;

    Info & info = utente->getInfo();
    std::cout << info.getNome() << std::endl;

    return a.exec();
}
