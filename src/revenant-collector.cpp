#include <revenant-collector.hpp>
#include <algorithm>
#include "revenant-external.h"
#include "service/snapshotservice.h"
#include "service/stacktraceservice.h"

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
    StackTraceService().printStackTrace();
}

std::vector<Revenant::StackEntry> Revenant::getStacktrace()
{
    return StackTraceService().getStackTrace();
}

bool Revenant::takeSnapshot()
{
    return SnapshotService().takeSnapshot();
}
