#include <revenant-collector.hpp>
#include <algorithm>
#include "revenant-external.h"

bool Revenant::setupSignalHandlers(const std::vector<SigType>& signals)
{
    return std::all_of(signals.cbegin(), signals.cend(), [](SigType sig)
    {
       return External::setup_one_signal_handler(sig);
    });
}

bool Revenant::setupSignalHandler(const SigType& sig)
{
    return External::setup_one_signal_handler(sig);
}

void Revenant::printStacktrace()
{
    return External::print_stacktrace();
}

void Revenant::snapshot(DumpConfigDesc desc)
{
    //return External::snapshot(desc);
}
