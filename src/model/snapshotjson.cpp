#include "model/snapshotjson.h"

#include "revenant-collector.hpp"

struct SnapshotJson::Impl
{
    std::vector<Revenant::StackEntry> entries;
};

SnapshotJson::SnapshotJson(const std::vector<Revenant::StackEntry>& stackEntries) : _impl(std::make_unique<Impl>(stackEntries))
{}

SnapshotJson::~SnapshotJson() = default;

JsonType SnapshotJson::toJson() const
{
    JsonType snapshot;
    auto arr = JsonType::array({});
    for (const auto& entry : _impl->entries)
    {
        JsonType jEntry;
        jEntry["name"] = entry.name();
        jEntry["file"] = entry.file();
        jEntry["line"] = entry.line();
        arr.push_back(jEntry);
    }

    snapshot["stack_trace"] = std::move(arr);

    return snapshot;
}
