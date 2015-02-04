#include "userinterface_model.h"

UserInterface_Model::UserInterface_Model()
{
}


Database * UserInterface_Model::getDatabase() const { return database; }


smartptr_utente & UserInterface_Model::getUser() { return user; }


void UserInterface_Model::setDatabase( Database * db ) { database = db; }
