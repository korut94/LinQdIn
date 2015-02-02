#include "admininterface_controller.h"


void AdminInterface_Controller::connetti() const
{
    connect( view,
             SIGNAL( requestToSearchUsers() ),
             this,
             SLOT( setSearchWindow() ) );

    connect( view,
             SIGNAL( requestToAddUser() ),
             this,
             SLOT( setInsertWindow() ) );

    connect( view,
             SIGNAL( requestToViewUsers() ),
             this,
             SLOT( viewUsers() ) );

    connect( view,
             SIGNAL( requestToViewUser( const QString &) ),
             this,
             SLOT( setUserWindow( const QString & ) ) );

    connect( this,
             SIGNAL( updateListUsers( const QVector<smartptr_utente> & ) ),
             view,
             SIGNAL( updateTable( const QVector<smartptr_utente> & ) ) );

    connect( view,
             SIGNAL( requestToRemoveUser() ),
             this,
             SLOT( removeUserSelected() ) );
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
                    db->getUsers( SearchGroupUtente::ByUsername( username ) );

    while( !ris.isEmpty() )
    {
        i++;

        username.replace( 0, username.length(), path + QString::number( i ) );

        ris = db->getUsers( SearchGroupUtente::ByUsername( username )  );
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

    QVector<smartptr_utente> all = db->getUsers( SearchGroupUtente::All() );

    setUserWindow( utente );

    model->actualUser() = utente;

	emit updateListUsers( all );
}


void AdminInterface_Controller::removeUserSelected()
{
    model->getDatabase()->remove( model->actualUser() );
    model->actualUser() = nullptr;

    viewUsers();
    view->setFrameUtility( new QWidget() ); //schermata vuota
}


void AdminInterface_Controller::setInsertWindow()
{
    model->actualUser() = nullptr;

    insert = new UserInsert();

    connect( insert,
             SIGNAL( error( ErrorState::Type ) ),
             insert,
             SLOT( manageLocalError( ErrorState::Type ) ) );

    connect( insert,
             SIGNAL( insert( const Info &) ),
             this,
             SLOT( addUser( const Info & ) ) );

    view->setFrameUtility( insert );
}


void AdminInterface_Controller::setSearchWindow()
{
    model->actualUser() = nullptr;

    UserSearch * search = new UserSearch();

    connect( search,
             SIGNAL( search( const Info & ) ),
             this,
             SLOT( searchUser( const Info & ) ) );

    view->setFrameUtility( search );
}


void AdminInterface_Controller::setUserWindow( const QString & username )
{
    Database * db = model->getDatabase();

    QVector<smartptr_utente> user = db->getUsers(
                                SearchGroupUtente::ByUsername( username ) );

    if( user.size() > 0 ) setUserWindow( user[0] );
}


void AdminInterface_Controller::setUserWindow( const smartptr_utente & user )
{
    UserInterface_View * viewUser = new UserInterface_View( user );

    view->setFrameUtility( viewUser );

    model->actualUser() = user;
}


void AdminInterface_Controller::searchUser( const Info & info )
{
    Database * db = model->getDatabase();

    QString name = info.getPersonal().getNome();
    QString surname = info.getPersonal().getCognome();

    QVector<smartptr_utente> utente = db->getUsers( SearchGroupUtente::
                                          ByNameAndSurname( name, surname ) );

    emit updateListUsers( utente );
}


void AdminInterface_Controller::viewUsers()
{
    Database * db = model->getDatabase();

    QVector<smartptr_utente> all = db->getUsers( SearchGroupUtente::All() );

    emit updateListUsers( all );
}


AdminInterface_Controller::
AdminInterface_Controller( AdminInterface_Model * m, AdminInterface_View * v )
                           : model( m ),
                             view( v ),
                             insert( nullptr )
{
    connetti();
}


AdminInterface_Controller::~AdminInterface_Controller()
{
    delete view;
    delete model;
}


AdminInterface_View * AdminInterface_Controller::getView() const
{
    return view;
}
