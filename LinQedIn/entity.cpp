#include "entity.h"

Entity::Entity() {}

Entity::Entity( const QString & user, const Info & i )
                : username( user ), info( i ){}


bool Entity::operator==( const Entity & user ) const
{
    return ( username == user.getUsername() );
}


bool Entity::operator!=( const Entity & user ) const
{
    return ( username != user.getUsername() );
}


Info & Entity::getInfo()
{
    return info;
}


const Info & Entity::getInfo() const
{
    return info;
}


QString Entity::getUsername() const
{
    return username;
}


void Entity::setUsername( const QString & u )
{
    username = u;
}
