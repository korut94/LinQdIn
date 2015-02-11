#include "admininterface_model.h"

AdminInterface_Model::AdminInterface_Model()
                      : database( new DatabaseXmlFile( "Database.xml" ) ),
                        userSelected( nullptr )
{
}


AdminInterface_Model::~AdminInterface_Model()
{
    delete database;
}


DatabaseXmlFile * AdminInterface_Model::getDatabase() const
{
    return database;
}


smartptr_utente & AdminInterface_Model::actualUser()
{
    return userSelected;
}
