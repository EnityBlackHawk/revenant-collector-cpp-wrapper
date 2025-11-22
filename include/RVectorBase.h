#pragma once
#include <memory>

namespace Revenant
{
    class RVectorBase
    {

    protected:
        struct Impl;
        RVectorBase();
        void initialize(char*& data, std::size_t typeSize, std::size_t size);
        [[nodiscard]] const char* get(int index) const;

    private:
        Impl* _impl;

    };
}


