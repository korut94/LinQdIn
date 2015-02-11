#ifndef USERINTERFACE_MODEL_H
#define USERINTERFACE_MODEL_H

#include "database.h"
#include "utenteexecutive.h"

class UserInterface_Model
{
    private:
        smartptr_utente actualUser; //pagina utente attuale
        smartptr_utente registerUser; //utente registrato
        Database * database;

    public:
        UserInterface_Model();

        Database * getDatabase() const;
        smartptr_utente & getActualUser();
        smartptr_utente & getRegisterUser();

        void setDatabase( Database * );
};

#endif // USERINTERFACE_MODEL_H
