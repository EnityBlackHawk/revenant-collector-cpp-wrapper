#pragma once
#include <vector>
#include "DumpConfigDesc.h"

namespace Revenant {

    using SigType = int;

    bool setupSignalHandlers(const std::vector<SigType>& signals);
    bool setupSignalHandler(const SigType& signal);
    void snapshot(DumpConfigDesc);

}
