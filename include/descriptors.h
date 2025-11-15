#ifndef REVENANTCOLLECTORCPP_DESCRIPTORS_H
#define REVENANTCOLLECTORCPP_DESCRIPTORS_H

template <typename T>
struct RVector
{
    const T* data;
    std::size_t size;
};

enum class UserDataType
{
    String = 0,
    Number = 1,
    Boolean = 2,
    Blob = 3,
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



#endif //REVENANTCOLLECTORCPP_DESCRIPTORS_H