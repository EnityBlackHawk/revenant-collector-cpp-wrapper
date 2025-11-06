#pragma once
#include <vector>

namespace Revenant {

    using SigType = int;

    bool setupSignalHandlers(const std::vector<SigType>& signals);
    bool setupSignalHandler(const SigType& signal);

}
