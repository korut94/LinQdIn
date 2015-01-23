#include "checkgroupinput.h"

CheckGroupInput::CheckName::check( const QString & name )
{
    return name.contains( "[a-zA-Z]" );
}
