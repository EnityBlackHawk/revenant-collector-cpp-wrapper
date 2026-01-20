#pragma once
#include "stacktraceservice.h"
#include "model/snapshotconfigdesc.h"
#include "model/snapshotresult.h"

using namespace Revenant;

class SnapshotService
{

public:
    explicit SnapshotService(const SnapshotConfigDesc& configDesc);
    SnapshotResult takeSnapshot() const;


private:

    std::string generateSnapshotFileName() const;

    StackTraceService _stackTraceService;
    SnapshotConfigDesc _configDesc;
};
