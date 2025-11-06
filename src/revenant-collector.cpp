#include <revenant-collector.hpp>
#include <algorithm>
#include "revenant-external.h"

bool Revent::setupSignalHandlers(const std::vector<SigType>& signals)
{
    return std::all_of(signals.cbegin(), signals.cend(), [](SigType sig)
    {
       return setup_one_signal_handler(sig);
    });
}

bool Revent::setupSignalHandler(const SigType& signal)
{
    return setup_one_signal_handler(signal);
}
