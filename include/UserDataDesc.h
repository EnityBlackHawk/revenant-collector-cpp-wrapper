#ifndef REVENANTCOLLECTORCPP_USERDATADESC_H
#define REVENANTCOLLECTORCPP_USERDATADESC_H
#include "UserDataType.h"
#include <string>

namespace Revenant
{
    struct UserDataDesc
    {
        std::string key;
        UserDataType dataType;
    };

}



#endif //REVENANTCOLLECTORCPP_USERDATADESC_H