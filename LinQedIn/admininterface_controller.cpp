#include "admininterface_controller.h"


void AdminInterface_Controller::connetti() const
{
    QObject::connect( view,
                      SIGNAL( requestToSearchUsers() ),
                      this,
                      SLOT( setSearchWindow() ) );

    QObject::connect( view,
                      SIGNAL( requestToAddUser() ),
                      this,
                      SLOT( setInsertWindow() ) );
}


void AdminInterface_Controller::addUser( const Info & info )
{
    smartptr_utente utente;

    Database * db = model->getDatabase();

    int i = 0;

    QString path = info.getPersonal().getNome() +
                   '.' +
                   info.getPersonal().getCognome() +
                   '.';

    QString username = path + QString::number( i );

    QVector<smartptr_utente> ris =
                    db->getUser( SearchGroupUtente::ByUsername( username ) );

    while( !ris.isEmpty() )
    {
        i++;

        username.replace( 0, username.length(), path + QString::number( i ) );

        ris = db->getUser( SearchGroupUtente::ByUsername( username )  );
    }

    switch( insert->getAccoutTypeSet() )
    {
        case LevelAccess::Basic : utente = new UtenteBasic( username, info );
                                  break;
        case LevelAccess::Business : utente = new UtenteBusiness( username,
                                                                  info );
                                     break;
        case LevelAccess::Executive : utente = new UtenteExecutive( username,
                                                                    info );
                                      break;

        default : utente = new UtenteBusiness( username, info );
    }

    db->insert( utente );

    delete insert;
    insert = nullptr;

    QVector<smartptr_utente> all = db->getUser( SearchGroupUtente::All() );

    QVector<Info> infoAll;

    for( QVector<smartptr_utente>::const_iterator itr = all.begin();
         itr != all.end();
         itr++ )
    {
        infoAll.push_back( (*itr)->getInfo() );
    }

    view->updateListUsers( infoAll );
    setUserWindow( info );
}


void AdminInterface_Controller::catchError( ErrorState::Type type )
{

}


void AdminInterface_Controller::setInsertWindow()
{
    if( insert == nullptr )
    {
        insert = new UserInsert();
        connect( insert,
                 SIGNAL( error( ErrorState::Type ) ),
                 insert,
                 SLOT( manageLocalError( ErrorState::Type ) ) );

        connect( insert,
                 SIGNAL( insert( const Info &) ),
                 this,
                 SLOT( addUser( const Info & ) ) );
    }

    view->setFrameUtility( insert->getView() );
}


void AdminInterface_Controller::setSearchWindow()
{
    UserSearch * search = new UserSearch();

    connect( search,
             SIGNAL( searchUser( const Info & ) ),
             this,
             SLOT( test( const Info & ) ) );

    view->setFrameUtility( search );
}


void AdminInterface_Controller::setUserWindow( const Info & info )
{
    UserInterface_View * user = new UserInterface_View();

    view->setFrameUtility( user );
}


void AdminInterface_Controller::test( const Info & info ) const
{
    std::cout << info.getPersonal().getNome().toStdString() << std::endl;
}


AdminInterface_Controller::
AdminInterface_Controller( AdminInterface_Model * m, AdminInterface_View * v )
                           : model( m ), view( v ), insert( nullptr )
{
    connetti();
}


AdminInterface_Controller::~AdminInterface_Controller()
{
    delete insert;
    delete view;
    delete model;
}


AdminInterface_View * AdminInterface_Controller::getView() const
{
    return view;
}
