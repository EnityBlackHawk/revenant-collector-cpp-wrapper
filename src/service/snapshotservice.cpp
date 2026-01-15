#include "service/snapshotservice.h"
#include <nlohmann/json.hpp>
#include <filesystem>
#include <chrono>
#include <fstream>

using json = nlohmann::json;
using namespace Revenant;

SnapshotService::SnapshotService(const SnapshotConfigDesc& configDesc):
    _configDesc(configDesc)
{}

SnapshotResult SnapshotService::takeSnapshot() const
{
    std::vector<StackEntry> stackTrace = _stackTraceService.getStackTrace();
    std::string fileName = generateSnapshotFileName();

    json snapshot;
    auto arr = json::array({});
    for (const auto& entry : stackTrace)
    {
        json jEntry;
        jEntry["name"] = entry.name();
        jEntry["file"] = entry.file();
        jEntry["line"] = entry.line();
        arr.push_back(jEntry);
    }

    snapshot["stack_trace"] = std::move(arr);

    std::ofstream file(fileName);

    if (!file.is_open())
    {
        return {false, std::move(fileName)};
    }

    file << snapshot.dump();
    file.close();

    return {true, std::move(fileName)};


}

std::string SnapshotService::generateSnapshotFileName() const
{
    // TODO implement on a dedicated service
    auto fileName = std::string(_configDesc.snapshotTemplatedName);
    size_t pos = fileName.find("{#TIME}");
    if (pos != std::string::npos)
    {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        fileName.replace(pos, 7, std::to_string(now_c));
    }

    return  _configDesc.outputPath / fileName;

}
