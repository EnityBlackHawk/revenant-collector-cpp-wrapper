#include "DumpConfigDesc.h"
#include "DumpConfigDescImpl.h"

namespace Revenant
{
    DumpConfigDesc::DumpConfigDesc(std::string&& dumpDirectory, std::string&& namingPattern, RVector<UserDataDesc>&& userDataDesc):
        _impl(std::make_unique<Impl>(Impl{std::move(dumpDirectory), std::move(namingPattern), std::move(userDataDesc)}))
    {
    }

    DumpConfigDesc::~DumpConfigDesc() = default;

    const std::string& DumpConfigDesc::dumpDirectory() const
    {
        return _impl->dumpDirectory;
    }

    const std::string& DumpConfigDesc::namingPattern() const
    {
        return _impl->namingPattern;
    }

    const RVector<UserDataDesc>& DumpConfigDesc::userDataDesc() const
    {
        return _impl->userDataDesc;
    }
}
