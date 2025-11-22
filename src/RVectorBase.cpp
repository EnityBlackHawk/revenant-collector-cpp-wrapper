#include "RVectorBase.h"
#include "descriptors.h"

namespace Revenant
{

    struct RVectorBase::Impl {

        ffi::RVector<char> _data;
        size_t _unitSize;

    };

    RVectorBase::RVectorBase() : _impl(nullptr)
    {}

    void RVectorBase::initialize(char*& data, const std::size_t typeSize, const std::size_t size)
    {
        _impl = new Impl();
        _impl->_data.data = data;
        _impl->_data.size = size;
        _impl->_unitSize = typeSize;
    }

    const char* RVectorBase::get(int index) const
    {
        return _impl->_data.data + index * _impl->_unitSize;
    }
}

