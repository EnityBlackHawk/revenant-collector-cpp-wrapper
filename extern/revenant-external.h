#pragma once
#include "descriptors.h"

namespace External
{
    extern "C" bool setup_one_signal_handler(int signal);
    extern "C" void print_stacktrace();
    extern "C" void snapshot(DumpConfigDesc);
}

