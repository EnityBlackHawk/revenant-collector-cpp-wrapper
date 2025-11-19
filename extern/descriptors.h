#ifndef REVENANTCOLLECTORCPP_DESCRIPTORS_H
#define REVENANTCOLLECTORCPP_DESCRIPTORS_H
#include "UserDataType.h"

using namespace Revenant;

namespace ffi
{
    template <typename T>
    struct RVector
    {
        const T* data;
        std::size_t size;
    };

    struct UserDataDesc
    {
        const char* key;
        UserDataType dataType;
    };

    struct DumpConfigDesc
    {
        const char* dumpDirectory;
        const char* namingPatter;
        RVector<UserDataDesc> userDataDesc;
    };
}



#endif //REVENANTCOLLECTORCPP_DESCRIPTORS_H