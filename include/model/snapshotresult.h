#pragma once
#include <string>
#include <memory>

class SnapshotResult
{

public:
    SnapshotResult(bool result, std::string&& filePath);
    ~SnapshotResult();
    bool result() const;
    const std::string& filePath() const;


private:
    struct Impl;
    const std::unique_ptr<Impl> _impl;

};
