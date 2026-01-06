#pragma once

namespace External
{

    struct StackEntry
    {
        const char* name;
        const char* file;
        const char* line;
    };

    extern "C" bool setup_one_signal_handler(int signal);
    extern "C" void print_stacktrace();
    extern "C" StackEntry* get_stacktrace(size_t* size);
    extern "C" void free_stacktrace(StackEntry* entries, size_t size);
}

