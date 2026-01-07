#pragma once
#include "stacktraceservice.h"

class SnapshotService
{

public:
    bool takeSnapshot();


private:
    StackTraceService _stackTraceService;
};
