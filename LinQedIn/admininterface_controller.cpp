#include "admininterface_controller.h"

bool AdminInterface_Controller::modified() const
{
    return model->getDatabase()->isModified();
}


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

    connect( view,
             SIGNAL( requestToSaveDB() ),
             this,
             SLOT( saveDB() ) );

    connect( view,
             SIGNAL( requestToLoadDB() ),
             this,
             SLOT( loadDB() ) );
}


void AdminInterface_Controller::test( const QString & username ) const
{
    std::cout << "Prova: " << username.toStdString() << std::endl;
}


smartptr_utente AdminInterface_Controller::
                createUser( const QString & username,
                            const Info & info,
                            LevelAccess::Type level ) const
{
    switch( level )
    {
        case LevelAccess::Basic : return new UtenteBasic( username, info );
        case LevelAccess::Business : return new UtenteBusiness( username,
                                                                info );
        case LevelAccess::Executive : return new UtenteExecutive( username,
                                                                  info );

        default : return new UtenteBusiness( username, info );
    }
}


smartptr_utente AdminInterface_Controller::
                createUser( const smartptr_utente & user,
                            LevelAccess::Type level )
{
    switch( level )
    {
        case LevelAccess::Basic : return new UtenteBasic( *user );
        case LevelAccess::Business : return new UtenteBusiness( *user );
        case LevelAccess::Executive : return new UtenteExecutive( *user );

        default : return new UtenteBusiness( *user );
    }
}


void AdminInterface_Controller::addUser( const Info & info,
                                         LevelAccess::Type level )
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

    utente = createUser( username, info, level );
    db->insert( utente );
    setUserWindow( utente );

    model->actualUser() = utente;

    viewUsers();
}


void AdminInterface_Controller::loadDB()
{
    DatabaseIO * db = model->getDatabase();

    QMessageBox msgBox;

    /*
    if( !db->isLoaded()  )
    {
        if( db->isModified() )
        {
            msgBox.setText( "The database has just been uploaded. Reload?" );
            msgBox.setInformativeText( "All the modifications will be lost" );
            msgBox.setStandardButtons( QMessageBox::Ok |
                                       QMessageBox::Cancel );
            msgBox.setDefaultButton( QMessageBox::Open );

            ret = msgBox.exec();
        }

        if( ret != QMessageBox::Cancel )
        {
            if( ret == QMessageBox::Ok )
            {
                QVector<smartptr_utente> risp =
                        db->getUsers( SearchGroupUtente::All() );

                std::for_each( risp.begin(),
                               risp.end(),
                               [ &db ]( const smartptr_utente & user )
                               {
                                   db->remove( user );
                               });
            }

            if( db->load() ) msgBox.setText( tr( "Upload completed" ) );
            else msgBox.setText( db->error() );

            msgBox.setStandardButtons( QMessageBox::Ok );
            msgBox.setDefaultButton( QMessageBox::Ok );
        }
    }
    */

    if( !db->isLoaded() )
    {
        if( db->load() ) msgBox.setText( tr( "Upload completed" ) );
        else
        {
            msgBox.setText( tr( "Error loading file" ) );
            msgBox.setInformativeText( db->error() );
        }

        msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::Cancel );
        msgBox.setDefaultButton( QMessageBox::Ok );

        msgBox.exec();
    }

    else if( db->isLoaded() || db->isModified() )
    {
        msgBox.setText( "The database has just been uploaded. Reload?" );
        msgBox.setInformativeText( "All the modifications will be lost" );
        msgBox.setStandardButtons( QMessageBox::Ok |
                                   QMessageBox::Cancel );
        msgBox.setDefaultButton( QMessageBox::Open );

        int ret = msgBox.exec();

        if( ret == QMessageBox::Ok )
        {
            QVector<smartptr_utente> risp =
                    db->getUsers( SearchGroupUtente::All() );

            std::for_each( risp.begin(),
                           risp.end(),
                           [ &db ]( const smartptr_utente & user )
                           {
                               db->remove( user );
                           });

            if( db->load() ) msgBox.setText( tr( "Upload completed" ) );
            else
            {
                //reinserisco i puntatori nel database
                std::for_each( risp.begin(),
                               risp.end(),
                               [ &db ]( const smartptr_utente & user )
                               {
                                   db->insert( user );
                               });

                msgBox.setText( tr( "Error loading file" ) );
                msgBox.setInformativeText( db->error() );
            }

            msgBox.setStandardButtons( QMessageBox::Ok | QMessageBox::Cancel );
            msgBox.setDefaultButton( QMessageBox::Ok );

            msgBox.exec();
        }
    }

	viewUsers();
}


void AdminInterface_Controller::modifyUser( const Info & info,
                                            LevelAccess::Type level )
{
    Database * db = model->getDatabase();
    smartptr_utente & user = model->actualUser();

    //Cambiati i permessi
    if( user->typeAccount() != level  )
    {
        db->remove( user );

        user->getInfo() = info; //modifica fuori dal database
        user = createUser( user, level );

        db->insert( user );
    }
    else db->modify( user, info );

    setUserWindow( user );
    viewUsers();
}


void AdminInterface_Controller::removeUserSelected()
{
    model->getDatabase()->Database::remove( model->actualUser() );
    model->actualUser() = nullptr;

    viewUsers();
    view->setFrameUtility( new QWidget() ); //schermata vuota
}


void AdminInterface_Controller::reset()
{
    viewUsers();
    if( model->actualUser() != nullptr ) setUserWindow( model->actualUser() );
}


void AdminInterface_Controller::saveDB()
{
    QMessageBox msgBox;

    if( model->getDatabase()->isModified() )
    {
        model->getDatabase()->save();
        msgBox.setText( tr( "Your modification have been apported" ) );
    }
    else msgBox.setText( tr( "There are no modification" ) );

    msgBox.setStandardButtons( QMessageBox::Ok );
    msgBox.setDefaultButton( QMessageBox::Ok );
    msgBox.exec();
}


void AdminInterface_Controller::setInsertWindow()
{
    model->actualUser() = nullptr;

    UserInsert * insert = new UserInsert();

    connect( insert,
             SIGNAL( error( ErrorState::Type ) ),
             insert,
             SLOT( manageLocalError( ErrorState::Type ) ) );

    connect( insert,
             SIGNAL( insert( const Info &, LevelAccess::Type ) ),
             this,
             SLOT( addUser( const Info &, LevelAccess::Type ) ) );

    view->setFrameUtility( insert );
}


void AdminInterface_Controller::setModifyWindow()
{
    UserModified * modify = new UserModified( model->actualUser(),
                                              LevelAccess::Master );

    connect( modify,
             SIGNAL( modify( const Info &, LevelAccess::Type ) ),
             this,
             SLOT( modifyUser( const Info &, LevelAccess::Type ) ) );

    connect( modify,
             SIGNAL( error( ErrorState::Type ) ),
             modify,
             SLOT( manageLocalError( ErrorState::Type ) ) );

    view->setFrameUtility( modify );
}


void AdminInterface_Controller::setSearchWindow()
{
    model->actualUser() = nullptr;

    UserSearch * search = new UserSearch( model->getDatabase() );

    connect( search,
             SIGNAL( search( const QVector<smartptr_utente> & ) ),
             this,
             SIGNAL( updateListUsers( const QVector<smartptr_utente> & ) ) );

    connect( search,
             SIGNAL( error( ErrorState::Type ) ),
             search,
             SLOT( manageLocalError( ErrorState::Type ) ) );

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
    ViewI * viewUser = new ViewI();
    viewUser->loadMainPage( user );

    connect( viewUser,
             SIGNAL( requestModify() ),
             this,
             SLOT( setModifyWindow() ) );

    view->setFrameUtility( viewUser );
    model->actualUser() = user;
}


void AdminInterface_Controller::viewUsers()
{
    Database * db = model->getDatabase();

    QVector<smartptr_utente> all = db->getUsers( SearchGroupUtente::All() );

    emit updateListUsers( all );
}


AdminInterface_Controller::
AdminInterface_Controller( UserInterface_Controller * ctrlUser,
                           AdminInterface_Model * m,
                           AdminInterface_View * v )
                           : model( m ),
                             view( v )
{
    ctrlUser->linkDatatabase( model->getDatabase() );

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
