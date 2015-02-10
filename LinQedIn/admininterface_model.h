#ifndef ADMININTERFACE_MODEL_H
#define ADMININTERFACE_MODEL_H

#include "databasexmlfile.h"

class AdminInterface_Model
{
    private:
        DatabaseXmlFile * database;
        smartptr_utente userSelected;

    public:
        AdminInterface_Model();
        ~AdminInterface_Model();

        DatabaseXmlFile * getDatabase() const;
        smartptr_utente & actualUser();
};

#endif // ADMININTERFACE_MODEL_H
