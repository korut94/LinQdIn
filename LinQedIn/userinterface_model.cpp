#include "userinterface_model.h"

UserInterface_Model::UserInterface_Model()
{
}


Database * UserInterface_Model::getDatabase() const { return db; }


smartptr_utente & UserInterface_Model::getUser() { return user; }
