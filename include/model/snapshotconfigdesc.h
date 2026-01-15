#pragma once

#include <filesystem>

struct SnapshotConfigDesc
{
    std::filesystem::path outputPath = std::filesystem::temp_directory_path();
    const char* snapshotTemplatedName = "snapshot-{#TIME}.json";
};