#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#include "hashgrouputente.h"
#include "hashlistutente.h"
#include "utente.h"
#include "searchgrouputente.h"
#include "smartptr_utente.h"
#include "sortlist.h"
#include "sortgrouputente.h"

typedef SortList<SortGroupUtente::AlfabeticoDec,smartptr_utente>
        SortListName;

struct Crescente
{
    bool operator()( int a, int b ) const
    {
        return a < b;
    }
};

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );

    MainWindow w;
    w.show();

    Info info1( "Andrea",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info2( "Bottino",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info3( "Fiestrella",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info4( "Ziestrella",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info5( "Ylenia",
                "Mantovani",
                "3406936174",
                "17/09/1994");
    Info info6( "Abari",
                "Mantovani",
                "3406936174",
                "17/09/1994");

    HashListUtente<HashGroupUtente::AlfabeticoDecUpCase,
                   SortGroupUtente::AlfabeticoCre> entry;

    smartptr_utente user[6];

    user[0] = new Utente( "korut94", "2322322", info1 );
    user[1] = new Utente( "korut94", "2322322", info2 );
    user[2] = new Utente( "korut94", "2322322", info3 );
    user[3] = new Utente( "korut94", "2322322", info4 );
    user[4] = new Utente( "korut94", "2322322", info5 );
    user[5] = new Utente( "korut94", "2322322", info6 );

    for( int i = 0; i < 6; i++ ) entry.insert( *user[i] );

    std::cout << entry << std::endl;

    return a.exec();
}
