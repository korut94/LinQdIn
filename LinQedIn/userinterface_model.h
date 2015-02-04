#ifndef USERINTERFACE_MODEL_H
#define USERINTERFACE_MODEL_H

#include "database.h"
#include "utenteexecutive.h"

class UserInterface_Model
{
    private:
        smartptr_utente user;
        Database * db;

    public:
        UserInterface_Model();

        Database * getDatabase() const;
        smartptr_utente & getUser();
};

#endif // USERINTERFACE_MODEL_H
