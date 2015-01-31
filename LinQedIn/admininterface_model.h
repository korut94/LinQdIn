#ifndef ADMININTERFACE_MODEL_H
#define ADMININTERFACE_MODEL_H

#include "database.h"

class AdminInterface_Model
{
    private:
        Database * database;

    public:
        AdminInterface_Model();
        ~AdminInterface_Model();

        Database * getDatabase() const;
};

#endif // ADMININTERFACE_MODEL_H
