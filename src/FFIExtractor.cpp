#include "FFIExtractor.h"
#include "RVectorBaseImpl.h"


ffi::RVector<char>& FFIExtractor::extractRVector(const RVectorBase& vectorBase)
{
    return vectorBase._impl->_data;
}

ffi::DumpConfigDesc& FFIExtractor::extractDumpConfigDesc(const DumpConfigDesc& desc)
{

}
