#include "admininterface_model.h"

AdminInterface_Model::AdminInterface_Model() : database( new Database() )
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
