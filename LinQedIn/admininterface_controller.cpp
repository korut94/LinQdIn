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

    QObject::connect( view,
                      SIGNAL( requestToViewUsers() ),
                      this,
                      SLOT( viewUsers() ) );

    QObject::connect( view,
                      SIGNAL( requestToViewUser( const QString &) ),
                      this,
                      SLOT( test( const QString & ) ) );

	QObject::connect( this,
					  SIGNAL(
						 updateListUsers( const QVector<smartptr_utente & ) ),
					  view,
					  SIGNAL( updateTable( const QVector<smartptr_utente & ) ) 
					);
}


void AdminInterface_Controller::test( const QString & username ) const
{
    std::cout << "Prova: " << username.toStdString() << std::endl;
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

    setUserWindow( utente );
	emit updateListUsers( all );
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
    if( search == nullptr )
    {
        search = new UserSearch();

        connect( search,
                 SIGNAL( search( const Info & ) ),
                 this,
                 SLOT( searchUser( const Info & ) ) );
    }

    view->setFrameUtility( search->getView() );
}


void AdminInterface_Controller::setUserWindow( const smartptr_utente & user )
{
    UserInterface_View * viewUser = new UserInterface_View( user );

    view->setFrameUtility( viewUser );
}


void AdminInterface_Controller::searchUser( const Info & info ) const
{
    Database * db = model->getDatabase();

    QString name = info.getPersonal().getNome();
    QString surname = info.getPersonal().getCognome();

    QVector<smartptr_utente> utente = db->getUser( SearchGroupUtente::
                                          ByNameAndSurname( name, surname ) );

    view->updateListUsers( utente );
}


void AdminInterface_Controller::viewUsers()
{
    Database * db = model->getDatabase();

    QVector<smartptr_utente> all = db->getUser( SearchGroupUtente::All() );

    view->updateListUsers( all );
}


AdminInterface_Controller::
AdminInterface_Controller( AdminInterface_Model * m, AdminInterface_View * v )
                           : model( m ),
                             view( v ),
                             insert( nullptr ),
                             search( nullptr )
{
    connetti();
}


AdminInterface_Controller::~AdminInterface_Controller()
{
    delete insert;
    delete search;
    delete view;
    delete model;
}


AdminInterface_View * AdminInterface_Controller::getView() const
{
    return view;
}
