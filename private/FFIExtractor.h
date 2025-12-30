#pragma once
#include "descriptors.h"
#include "DumpConfigDesc.h"
#include "RVectorBase.h"

namespace Revenant
{
    class FFIExtractor
    {
    public:
        FFIExtractor() = delete;
        static ffi::RVector<char>& extractRVector(const RVectorBase& vectorBase);
        static ffi::DumpConfigDesc& extractDumpConfigDesc(const DumpConfigDesc& desc);
    };
}
