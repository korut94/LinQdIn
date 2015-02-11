#ifndef ERRORSTATE_H
#define ERRORSTATE_H

namespace ErrorState
{
    enum Type
    {
        EmptyValue,
        InvalidValue,
        LoginEmpty,
        LoginInvalid,
        None,
        NotFoundUser
    };
}

#endif // ERRORSTATE_H
