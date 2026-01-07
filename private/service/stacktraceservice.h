#pragma once

#include <vector>
#include "model/stackentry.h"

class StackTraceService
{
public:

    std::vector<Revenant::StackEntry> getStackTrace() const;
    void printStackTrace() const;

};
