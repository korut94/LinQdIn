#include "userinterface_controller.h"

void UserInterface_Controller::connetti( ViewI * vI ) const
{
    connect( vI, SIGNAL( requestModify() ), this, SLOT( setUserModify() ) );

    connect( vI,
             SIGNAL( requestLogout() ),
             this,
             SLOT( logoutUser() ) );

    connect( vI,
             SIGNAL( requestHome() ),
             this,
             SLOT( returnHome() ) );

    connect( vI,
             SIGNAL( requestSearch() ),
             this,
             SLOT( setUserSearch() ) );

    connect( this,
             SIGNAL( updateListFriends( const Utente::Rete & ) ),
             vI,
             SIGNAL( viewListFriends( const Utente::Rete & ) ) );

    connect( vI,
             SIGNAL( requestViewFriend( const QString & ) ),
             this,
             SLOT( setUserPage( const QString & ) ) );
}


void UserInterface_Controller::connetti( ViewBasic * vBasic ) const
{
    connect( vBasic,
             SIGNAL( requestAddFriend() ),
             this,
             SLOT( addFriend() ) );

    connect( vBasic,
             SIGNAL( requestHome() ),
             this,
             SLOT( returnHome() ) );

    connect( vBasic,
             SIGNAL( requestRemoveFriend() ),
             this,
             SLOT( removeFriend() ) );

    connect( this,
             SIGNAL( updateListFriends( const Utente::Rete & ) ),
             vBasic,
             SIGNAL( viewListFriends( const Utente::Rete & ) ) );

    connect( vBasic,
             SIGNAL( requestViewFriend( const QString & ) ),
             this,
             SLOT( setUserPage( const QString & ) ) );
}


void UserInterface_Controller::connetti( ViewBusiness * vBusiness ) const
{
    connect( vBusiness,
             SIGNAL( requestAddFriend() ),
             this,
             SLOT( addFriend() ) );

    connect( vBusiness,
             SIGNAL( requestHome() ),
             this,
             SLOT( returnHome() ) );

    connect( vBusiness,
             SIGNAL( requestRemoveFriend() ),
             this,
             SLOT( removeFriend() ) );

    connect( this,
             SIGNAL( updateListFriends( const Utente::Rete & ) ),
             vBusiness,
             SIGNAL( viewListFriends( const Utente::Rete & ) ) );

    connect( vBusiness,
             SIGNAL( requestViewFriend( const QString & ) ),
             this,
             SLOT( setUserPage( const QString & ) ) );
}


void UserInterface_Controller::connetti( ViewExecutive * vExecutive ) const
{
    connect( vExecutive,
             SIGNAL( requestAddFriend() ),
             this,
             SLOT( addFriend() ) );

    connect( vExecutive,
             SIGNAL( requestHome() ),
             this,
             SLOT( returnHome() ) );

    connect( vExecutive,
             SIGNAL( requestRemoveFriend() ),
             this,
             SLOT( removeFriend() ) );

    connect( this,
             SIGNAL( updateListFriends( const Utente::Rete & ) ),
             vExecutive,
             SIGNAL( viewListFriends( const Utente::Rete & ) ) );

    connect( vExecutive,
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

        ViewBase * viewUser;

        switch( level )
        {
            case LevelAccess::I :
            {
                ViewI * viewI = new ViewI();
                connetti( viewI );

                viewUser = viewI;

                break;
            }

            case LevelAccess::Basic :
            {
                ViewBasic * viewBasic = new ViewBasic();
                connetti( viewBasic );

                viewBasic->myFriend( registerUser->isFriendOf( user ) );

                viewUser = viewBasic;

                break;
            }

            case LevelAccess::Business :
            {
                ViewBusiness * viewBusiness = new ViewBusiness();
                connetti( viewBusiness );

                viewBusiness->myFriend( registerUser->isFriendOf( user ) );

                viewUser = viewBusiness;

                break;
            }

            case LevelAccess::Executive :
            {
                ViewExecutive * viewExecutive = new ViewExecutive();
                connetti( viewExecutive );

                viewExecutive->myFriend( registerUser->isFriendOf( user ) );

                viewUser = viewExecutive;

                break;
            }

            default: break;
        }

        viewUser->loadMainPage( user );

        //connetti( viewUser );

        model->getActualUser() = user;
        view->setFrameUtility( viewUser );
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
