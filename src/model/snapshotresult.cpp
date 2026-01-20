#include "model/snapshotresult.h"

namespace Revenant
{
    struct SnapshotResult::Impl {

        const bool result;
        const std::string filePath;

    };


    SnapshotResult::SnapshotResult(bool result, std::string&& filePath) : _impl(std::make_unique<Impl>(result, std::move(filePath)))
    {
    }

    SnapshotResult::~SnapshotResult() = default;

    bool SnapshotResult::result() const
    {
        return _impl->result;
    }

    const std::string& SnapshotResult::filePath() const
    {
        return _impl->filePath;
    }
}
