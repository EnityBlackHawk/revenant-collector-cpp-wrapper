#pragma once

#include <string>
#include <functional>
#include "userdatatypeenum.h"

namespace Revenant
{
    struct UserDataDesc
    {
        std::string name;
        UserDataTypeEnum type = UserDataTypeEnum::UNKNOWN;
        std::function<std::string()> collectorAction;
    };
}
