#pragma once

#include <filesystem>
#include <vector>
#include "userdatadesc.h"

namespace Revenant
{
    struct SnapshotConfigDesc
    {
        std::filesystem::path outputPath = std::filesystem::temp_directory_path();
        const char* snapshotTemplatedName = "snapshot-{#TIME}.json";
        std::vector<UserDataDesc> userData = {};
    };
}