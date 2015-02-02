#ifndef ADMININTERFACE_MODEL_H
#define ADMININTERFACE_MODEL_H

#include "database.h"

class AdminInterface_Model
{
    private:
        Database * database;
        smartptr_utente userSelected;

    public:
        AdminInterface_Model();
        ~AdminInterface_Model();

        Database * getDatabase() const;
        smartptr_utente & actualUser();
};

#endif // ADMININTERFACE_MODEL_H
