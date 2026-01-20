#pragma once

#include <string>
#include "userdatatypeenum.h"

namespace Revenant
{
    struct UserDataDesc
    {
        std::string name;
        std::string value;
        UserDataTypeEnum type = UserDataTypeEnum::UNKNOWN;
    };
}
