#include "RVector.h"

#include <cstring>

namespace Revenant
{
    template <typename T>
    RVector<T>::RVector(std::initializer_list<T> list): data(), size(list.size())
    {
        if (list.size() == 0)
        {
            data = nullptr;
            return;
        }

        data = new T[size];
        std::memcpy(data, list.begin(), list.end());
    }

}

