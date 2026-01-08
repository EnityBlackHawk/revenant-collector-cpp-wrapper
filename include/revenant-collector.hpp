#pragma once
#include <vector>

#include "model/stackentry.h"
#include "model/snapshotconfigdesc.h"
#include "model/snapshotresult.h"

namespace Revenant {

    using SigType = int;

    bool setupSignalHandlers(const std::vector<SigType>& sig);
    bool setupSignalHandler(const SigType& sig);
    void printStacktrace();
    std::vector<StackEntry> getStacktrace();
    SnapshotResult takeSnapshot(const SnapshotConfigDesc& configDesc);
}
