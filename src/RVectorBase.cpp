#include "RVectorBase.h"
#include "RVectorBaseImpl.h"

namespace Revenant
{

    RVectorBase::RVectorBase() = default;

    RVectorBase::RVectorBase(RVectorBase&& instance) noexcept {
        _impl = std::move(instance._impl);
    }

    RVectorBase::~RVectorBase() = default;

    void RVectorBase::initialize(char*& data, const std::size_t typeSize, const std::size_t size)
    {
        _impl = std::make_unique<Impl>();
        _impl->_data.data = data;
        _impl->_data.size = size;
        _impl->_unitSize = typeSize;
    }

    const char* RVectorBase::get(int index) const
    {
        if (index > static_cast<int>(_impl->_data.size) || index < 0)
        {
            return nullptr;
        }
        return _impl->_data.data + index * _impl->_unitSize;
    }
}

