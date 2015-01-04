#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#include "hashgrouputente.h"
#include "hashlistutente.h"
#include "utente.h"
#include "smartptr_utente.h"
#include "sortlist.h"
#include "sortgrouputente.h"

typedef SortList<SortGroupUtente::AlfabeticoCre,smartptr_utente>
        SortListName;

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );

    MainWindow w;
    w.show();

    SortListName list;

    Info info1( "Andrea",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info2( "Zottino",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info3( "Fiestrella",
                "Mantovani",
                "3406936174",
                "17/09/1994");

    smartptr_utente utenti[3];

    utenti[0] = new Utente( "korut94", "36633663", info1 );
    utenti[1] = new Utente( "bilbo94", "36633663", info2 );
    utenti[2] = new Utente( "giannsi94", "36633663", info3 );


    for( int i = 0; i < 3; i++ ) list.insert( utenti[i] );
    for( SortListName::const_iterator itr = list.constBegin();
         itr != list.end();
         itr++ )
    {
        std::cout << **itr << std::endl;
    }

    HashGroupUtente::AlfabeticoDecUpCase c;

    std::cout << c( "Babbo" ) << std::endl;

    HashListUtente<HashGroupUtente::AlfabeticoDecUpCase,
                   SortGroupUtente::AlfabeticoDec> database;



    return a.exec();
}
