#include <revenant-collector.hpp>
#include <algorithm>
#include "revenant-external.h"

bool Revenant::setupSignalHandlers(const std::vector<SigType>& signals)
{
    return std::all_of(signals.cbegin(), signals.cend(), [](SigType sig)
    {
       return setup_one_signal_handler(sig);
    });
}

bool Revenant::setupSignalHandler(const SigType& signal)
{
    return setup_one_signal_handler(signal);
}
