#ifndef REVENANTCOLLECTORCPP_DUMPCONFIGDESC_H
#define REVENANTCOLLECTORCPP_DUMPCONFIGDESC_H
#include <string>
#include "RVector.h"
#include "UserDataDesc.h"

namespace Revenant
{
    struct DumpConfigDesc
    {
        std::string dumpDirectory;
        std::string namingPattern;
        RVector<UserDataDesc> userDataDesc;
    };
}

#endif //REVENANTCOLLECTORCPP_DUMPCONFIGDESC_H
