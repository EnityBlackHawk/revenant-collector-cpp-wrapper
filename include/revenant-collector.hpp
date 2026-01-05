#pragma once
#include <vector>

namespace Revenant {

    using SigType = int;

    bool setupSignalHandlers(const std::vector<SigType>& sig);
    bool setupSignalHandler(const SigType& sig);
    void printStacktrace();

}
