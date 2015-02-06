#include "userinterface_model.h"

UserInterface_Model::UserInterface_Model() : actualUser( nullptr ),
                                             registerUser( nullptr )
{
}


Database * UserInterface_Model::getDatabase() const { return database; }


smartptr_utente & UserInterface_Model::getActualUser() { return actualUser; }


smartptr_utente & UserInterface_Model::getRegisterUser()
{
    return registerUser;
}


void UserInterface_Model::setDatabase( Database * db ) { database = db; }
