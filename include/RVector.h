#ifndef REVENANTCOLLECTORCPP_RVECTOR_H
#define REVENANTCOLLECTORCPP_RVECTOR_H
#include <cstring>
#include <vector>
#include "RVectorBase.h"

namespace Revenant
{
    template<typename T>
    class RVector : public RVectorBase
    {
    public:
        RVector(std::initializer_list<T> list)
        {
            char* data = static_cast<char*>(operator new(sizeof(T) * list.size()));
            std::memcpy(data, list.begin(), list.size() * sizeof(T));
            initialize(data, sizeof(T), list.size());
        }

        const T& operator[](int index) const
        {
            return *reinterpret_cast<const T*>(get(index));
        }

    };

}


#endif //REVENANTCOLLECTORCPP_RVECTOR_H