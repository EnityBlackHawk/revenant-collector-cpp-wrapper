#ifndef REVENANTCOLLECTORCPP_RVECTOR_H
#define REVENANTCOLLECTORCPP_RVECTOR_H
#include <vector>

namespace Revenant
{
    template<typename T>
    class RVector
    {
    public:
        RVector(std::initializer_list<T> list);

    private:
        T* data;
        std::size_t size;

    };
}


#endif //REVENANTCOLLECTORCPP_RVECTOR_H