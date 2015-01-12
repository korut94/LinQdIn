#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#include "database.h"
#include "frankenstein.h"
#include "hashgrouputente.h"
#include "hashlistutente.h"
#include "utente.h"
#include "searchgrouputente.h"
#include "smartptr_utente.h"
#include "sortlist.h"
#include "sortgrouputente.h"

typedef SortList<SortGroupUtente::NameCrescente,smartptr_utente>
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

    Database db;

    smartptr_utente user[6];

    user[0] = new Utente( "korut94", "2322322", info1 );
    user[1] = new Utente( "mtrut94", "2322322", info2 );
    user[2] = new Utente( "sertit94", "2322322", info3 );
    user[3] = new Utente( "beregont94", "2322322", info4 );
    user[4] = new Utente( "salmict94", "2322322", info5 );
    user[5] = new Utente( "gnat94", "2322322", info6 );

    for( int i = 0; i < 6; i++ ) db.insert( user[i] );

    smartptr_utente me = db.getUser(
                            SearchGroupUtente::ByUsername( "korut94" ) );

    std::cout << me->getInfo().getNome().toStdString()
              << " "
              << me->getInfo().getCognome().toStdString()
              << std::endl;

    return a.exec();
}
