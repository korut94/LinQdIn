#ifndef ENTITY_H
#define ENTITY_H

#include "info.h"
#include "smartclass.h"

class Entity : public SmartClass
{
    private:
        Info info;

        QString password; //class Password?
        QString username;

    public:
        Entity();
        Entity( const QString &, const QString &, const Info & );

        bool operator==( const Entity & ) const;
        bool operator!=( const Entity & ) const;

        Info & getInfo();
        const Info & getInfo() const;

        QString getPassword() const;
        QString getUsername() const;

        void setPassword( const QString & );
        void setUsername( const QString & );
};

#endif // ENTITY_H
