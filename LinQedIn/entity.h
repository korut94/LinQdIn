#ifndef ENTITY_H
#define ENTITY_H

#include "info.h"
#include "levelaccess.h"
#include "smartclass.h"

class Entity : public SmartClass
{
    private:
        Info info;

        QString username;

    public:
        Entity();
        Entity( const QString &, const Info & );

        bool operator==( const Entity & ) const;
        bool operator!=( const Entity & ) const;

        Info & getInfo();
        const Info & getInfo() const;

        QString getUsername() const;

        void setUsername( const QString & );
};

#endif // ENTITY_H
