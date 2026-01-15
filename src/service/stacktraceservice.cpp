#include <vector>

#include "model/stackentry.h"
#include "revenant-external.h"
#include "service/stacktraceservice.h"

std::vector<Revenant::StackEntry> StackTraceService::getStackTrace() const
{
    size_t size = 0;
    External::StackEntry* entries = External::get_stacktrace(&size);
    std::vector<Revenant::StackEntry> result;
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

void StackTraceService::printStackTrace() const
{
    External::print_stacktrace();
}
