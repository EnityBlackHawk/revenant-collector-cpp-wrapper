#pragma once
#include <csignal>
#include <vector>


namespace Revent {

    using SigType = decltype(SIGINT);

    bool setupSignalHandlers(const std::vector<SigType>& signals);
    bool setupSignalHandler(const SigType& signal);

}
