#include "service/snapshotservice.h"
#include <nlohmann/json.hpp>
#include <filesystem>
#include <fstream>

using json = nlohmann::json;
using namespace Revenant;

bool SnapshotService::takeSnapshot()
{
    std::vector<StackEntry> stackTrace = _stackTraceService.getStackTrace();
    json snapshot;
    snapshot["stack_trace"] = json::array({});
    for (const auto& entry : stackTrace)
    {
        json jEntry;
        jEntry["name"] = entry.name();
        jEntry["file"] = entry.file();
        jEntry["line"] = entry.line();
        snapshot["stack_trace"].push_back(jEntry);
    }


    std::ofstream file(std::filesystem::temp_directory_path() / "snapshot.json");
    file << snapshot.dump();
    file.close();

    return true;


}
