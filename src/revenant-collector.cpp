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

std::vector<Revenant::StackEntry> Revenant::getStacktrace()
{
    size_t size = 0;
    External::StackEntry* entries = External::get_stacktrace(&size);
    std::vector<StackEntry> result;
    result.reserve(size);
    for (size_t i = 0; i < size; ++i)
    {
        result.emplace_back(
            std::string(entries[i].name),
            std::string(entries[i].file),
            std::string(entries[i].line)
        );
    }
    External::free_stacktrace(entries, size);
    return result;
}
