#ifndef USERINTERFACE_MODEL_H
#define USERINTERFACE_MODEL_H

#include "database.h"
#include "utenteexecutive.h"

class UserInterface_Model
{
    private:
        smartptr_utente user;
        Database * database;

    public:
        UserInterface_Model();

        Database * getDatabase() const;
        smartptr_utente & getUser();

        void setDatabase( Database * );
};

#endif // USERINTERFACE_MODEL_H
