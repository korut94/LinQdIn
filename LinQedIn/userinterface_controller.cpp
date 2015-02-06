#include "userinterface_controller.h"

void UserInterface_Controller::connetti() const
{
    connect( view, SIGNAL( requestModify() ), this, SLOT( setUserModify() ) );

    connect( this,
             SIGNAL( display( QWidget * ) ),
             view,
             SLOT( setFrameUtility( QWidget * ) ) );

    connect( view,
             SIGNAL( error( ErrorState::Type ) ),
             this,
             SLOT( manageError( ErrorState::Type ) ) );

    connect( view,
             SIGNAL( requestLogin( const QString &) ),
             this,
             SLOT( setUserPage( const QString & ) ) );

    connect( view,
             SIGNAL( requestLogout() ),
             this,
             SLOT( logoutUser() ) );

    connect( view,
             SIGNAL( requestFriend() ),
             this,
             SLOT( addFriend() ) );

    connect( view,
             SIGNAL( requestHome() ),
             this,
             SLOT( returnHome() ) );

    connect( view,
             SIGNAL( requestSearch() ),
             this,
             SLOT( setUserSearch() ) );
}


void UserInterface_Controller::addFriend()
{
    std::cout << "Ciao" << std::endl;

    model->getDatabase()->linkUser( model->getActualUser(),
                                    model->getRegisterUser() );

    reset();
}


void UserInterface_Controller::logoutUser()
{
    model->getRegisterUser() = nullptr;
    view->loadLoginPage();
}


void UserInterface_Controller::manageError( ErrorState::Type error )
{
    switch( error )
    {
        case ErrorState::LoginEmpty :
             view->errorLoginMessage( tr( "Empty values" ) );
             break;

        case ErrorState::LoginInvalid :
             view->errorLoginMessage( tr( "Incorrect values" ) );
             break;

        case ErrorState::NotFoundUser :
             view->errorLoginMessage( tr( "Not found user" ) );
             break;
    }
}


void UserInterface_Controller::modifyUser( const Info & info )
{
    Database * db = model->getDatabase();
    smartptr_utente & user = model->getRegisterUser();

    db->modify( user, info );

    setUserPage( user->getUsername() );
}


void UserInterface_Controller::reset()
{
    smartptr_utente & user = model->getActualUser();

    if( user != nullptr )
    {
        Database * db = model->getDatabase();

        QVector<smartptr_utente> risp =
        db->getUsers( SearchGroupUtente::ByUsername( user->getUsername() ) );

        if( risp.size() > 0 )
        {
            user = risp[0];

            LevelAccess::Type level = ( user == model->getRegisterUser() ) ?
                                      LevelAccess::I : user->typeAccount();

            view->loadMainPage( user, level );
        }
    }
}


void UserInterface_Controller::returnHome()
{
    setUserPage( model->getRegisterUser() );
}


void UserInterface_Controller::
     searchUser( const QVector<smartptr_utente> & users )
{
    setUserPage( users[0] );
}


void UserInterface_Controller::setUserModify()
{
    UserModified * modified = new UserModified( model->getRegisterUser(),
                                                LevelAccess::I );

    connect( modified,
             SIGNAL( error( ErrorState::Type ) ),
             modified,
             SLOT( manageLocalError( ErrorState::Type ) ) );

    connect( modified,
             SIGNAL( modify( const Info &, LevelAccess::Type ) ),
             this,
             SLOT( modifyUser( const Info & ) ) );

    emit display( modified );
}


void UserInterface_Controller::setUserPage( const QString & username )
{
    Database * db = model->getDatabase();

    QVector<smartptr_utente> ris =
                db->getUsers( SearchGroupUtente::ByUsername( username ) );

    if( !ris.isEmpty() ) setUserPage( ris[0] );
    else manageError( ErrorState::NotFoundUser );
}


void UserInterface_Controller::setUserPage( const smartptr_utente & user )
{
    if( user != nullptr )
    {
        LevelAccess::Type level;

        if( model->getRegisterUser() == nullptr )
        {
            level = LevelAccess::I;
            model->getRegisterUser() = user;
        }

        else level = ( user == model->getRegisterUser() ) ?
                        LevelAccess::I : user->typeAccount();

        model->getActualUser() = user;

        view->loadMainPage( user, level );
    }
}


void UserInterface_Controller::setUserSearch()
{
    UserSearch * schUser = new UserSearch( model->getDatabase() );

    connect( schUser,
             SIGNAL( search( const QVector<smartptr_utente> & ) ),
             this,
             SLOT( searchUser( const QVector<smartptr_utente> & ) ) );

    connect( schUser,
             SIGNAL( error( ErrorState::Type ) ),
             schUser,
             SLOT( manageLocalError( ErrorState::Type ) ) );

    view->setFrameUtility( schUser );
}


UserInterface_Controller::UserInterface_Controller()
                          : view( new UserInterface_View() ),
                            model( new UserInterface_Model )
{
    view->loadLoginPage();

    connetti();
}


UserInterface_Controller::~UserInterface_Controller()
{
    delete view;
    delete model;
}


UserInterface_View * UserInterface_Controller::getView() const
{
    return view;
}


void UserInterface_Controller::linkDatatabase( Database * db )
{
    model->setDatabase( db );
}
