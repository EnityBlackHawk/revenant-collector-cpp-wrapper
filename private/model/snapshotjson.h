#pragma once

#include <memory>
#include <vector>

#include "interface/ijsonable.h"
#include "model/stackentry.h"

class SnapshotJson : public IJsonable
{
public:
    SnapshotJson(const std::vector<Revenant::StackEntry>& stackEntries);
    ~SnapshotJson();
    JsonType toJson() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> _impl;

};