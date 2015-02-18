#include "userinterface_controller.h"

void UserInterface_Controller::connetti( ViewBase * v ) const
{
    connect( v, SIGNAL( requestModify() ), this, SLOT( setUserModify() ) );

    connect( v,
             SIGNAL( requestLogout() ),
             this,
             SLOT( logoutUser() ) );

    connect( v,
             SIGNAL( requestHome() ),
             this,
             SLOT( returnHome() ) );

    connect( v,
             SIGNAL( requestSearch() ),
             this,
             SLOT( setUserSearch() ) );

    connect( v,
             SIGNAL( requestAddFriend() ),
             this,
             SLOT( addFriend() ) );

    connect( v,
             SIGNAL( requestRemoveFriend() ),
             this,
             SLOT( removeFriend() ) );

    connect( this,
             SIGNAL( updateListFriends( const Utente::Rete & ) ),
             v,
             SIGNAL( viewListFriends( const Utente::Rete & ) ) );

    connect( v,
             SIGNAL( requestViewFriend( const QString & ) ),
             this,
             SLOT( setUserPage( const QString & ) ) );
}


void UserInterface_Controller::addFriend()
{
    model->getDatabase()->linkUser( model->getActualUser(),
                                    model->getRegisterUser() );

    emit updateListFriends( model->getActualUser()->getContatti() );
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


void UserInterface_Controller::removeFriend()
{
    model->getDatabase()->unlinkUser( model->getActualUser(),
                                      model->getRegisterUser() );

    emit updateListFriends( model->getActualUser()->getContatti() );
}


void UserInterface_Controller::reset()
{
    Database * db = model->getDatabase();

    smartptr_utente & userReg = model->getRegisterUser();
    smartptr_utente & userAct = model->getActualUser();

    userReg = db->recoveryUser( userReg );
    userAct = db->recoveryUser( userAct );

    setUserPage( userAct );
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
    UserModified_Utente * modified =
            new UserModified_Utente( model->getRegisterUser() );

    connect( modified,
             SIGNAL( error( ErrorState::Type ) ),
             modified,
             SLOT( manageLocalError( ErrorState::Type ) ) );

    connect( modified,
             SIGNAL( modify( const Info & ) ),
             this,
             SLOT( modifyUser( const Info & ) ) );

    view->setFrameUtility( modified );
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

        smartptr_utente & registerUser = model->getRegisterUser();

        //Primo accesso
        if( registerUser == nullptr )
        {
            level = LevelAccess::I;
            registerUser = user;
        }

        else level = ( user == registerUser ) ?
                            LevelAccess::I : registerUser->typeAccount();

        if( level == LevelAccess::I )
        {
            ViewI * i = new ViewI();
            connetti( i );

            i->loadMainPage( user );
            view->setFrameUtility( i );
        }

        else
        {
            ViewOther * other;

            switch( level )
            {
                case LevelAccess::Basic : other = new ViewBasic();
                                          break;
                case LevelAccess::Business : other = new ViewBusiness();
                                             break;
                case LevelAccess::Executive : other = new ViewExecutive();
                                              break;
                default: break;
            }

            other->loadMainPage( user );

            connetti( other );
            other->myFriend( registerUser->isFriendOf( user ) );

            view->setFrameUtility( other );
        }

        model->getActualUser() = user;
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

    connect( view,
             SIGNAL( error( ErrorState::Type ) ),
             this,
             SLOT( manageError( ErrorState::Type ) ) );

    connect( view,
             SIGNAL( requestLogin( const QString &) ),
             this,
             SLOT( setUserPage( const QString & ) ) );
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
