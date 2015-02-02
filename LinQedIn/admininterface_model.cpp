#include "admininterface_model.h"

AdminInterface_Model::AdminInterface_Model()
                      : database( new Database() ),
                        userSelected( nullptr )
{
}


AdminInterface_Model::~AdminInterface_Model()
{
    delete database;
}


Database * AdminInterface_Model::getDatabase() const
{
    return database;
}


smartptr_utente & AdminInterface_Model::actualUser()
{
    return userSelected;
}
