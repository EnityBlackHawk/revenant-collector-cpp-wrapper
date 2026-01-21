#pragma once

#include <memory>
#include <string>

#include "interface/ijsonable.h"
#include "model/userdatatypeenum.h"

class UserDataValue : public IJsonable
{

public:
    UserDataValue(const std::string& name, const std::string& value, Revenant::UserDataTypeEnum type);
    UserDataValue(const UserDataValue& other);
    ~UserDataValue();

    const std::string& name() const;
    const std::string& value() const;
    Revenant::UserDataTypeEnum type() const;

    JsonType toJson() const override;

private:
    struct Impl;
    std::unique_ptr<Impl> _impl;

};
