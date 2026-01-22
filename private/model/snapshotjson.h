#pragma once

#include <memory>
#include <vector>

#include "interface/ijsonable.h"
#include "model/userdatavalue.h"
#include "model/stackentry.h"


class SnapshotJson : public IJsonable
{
public:
    SnapshotJson(const std::vector<Revenant::StackEntry>& stackEntries, const std::vector<UserDataValue>& userData);
    ~SnapshotJson();
    JsonType toJson() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> _impl;

};
