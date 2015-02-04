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


void UserInterface_Controller::setUserModify()
{
    UserModified * modified = new UserModified( new UtenteBusiness(),
                                                LevelAccess::Basic );

    emit display( modified );
}


void UserInterface_Controller::setUserPage( const QString & username )
{
    Database * db = model->getDatabase();

    QVector<smartptr_utente> ris =
                db->getUsers( SearchGroupUtente::ByUsername( username ) );

    if( !ris.isEmpty() )
    {
        model->getUser() = ris[0];
        view->loadMainPage( model->getUser(), LevelAccess::I );
    }

    else manageError( ErrorState::NotFoundUser );
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
