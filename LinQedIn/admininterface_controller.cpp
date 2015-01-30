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

    QObject::connect( this,
                      SIGNAL( display( QWidget * ) ),
                      view,
                      SLOT( setFrameUtility( QWidget * ) ) );
}


void AdminInterface_Controller::catchError()
{
    insert->setErrorMessage( tr( "There are incorrect values" ) );
}


void AdminInterface_Controller::setInsertWindow()
{
    if( insert == nullptr )
    {
        insert = new UserInsert();
        connect( insert,
                 SIGNAL( error() ),
                 this,
                 SLOT( catchError() ) );
    }

    emit display( insert->getView() );
}


void AdminInterface_Controller::setSearchWindow()
{
    UserSearch * search = new UserSearch();

    connect( search,
             SIGNAL( searchUser( const Info & ) ),
             this,
             SLOT( test( const Info & ) ) );

    emit display( search );
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
    delete model;
    delete view;
    delete insert;
}


AdminInterface_View * AdminInterface_Controller::getView() const
{
    return view;
}
