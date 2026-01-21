#include "model/userdatavalue.h"


struct UserDataValue::Impl
{
    std::string name;
    std::string value;
    Revenant::UserDataTypeEnum type;
};

UserDataValue::UserDataValue(const std::string& name, const std::string& value, Revenant::UserDataTypeEnum type) :
    _impl(std::make_unique<Impl>(name, value, type))
{
}

UserDataValue::UserDataValue(const UserDataValue& other) : _impl(std::make_unique<Impl>(other._impl->name, other._impl->value, other._impl->type))
{
}

UserDataValue::~UserDataValue() = default;

const std::string& UserDataValue::name() const
{
    return _impl->name;
}

const std::string& UserDataValue::value() const
{
    return _impl->value;
}

Revenant::UserDataTypeEnum UserDataValue::type() const
{
    return _impl->type;
}

JsonType UserDataValue::toJson() const
{
    JsonType obj;
    obj["value"] = _impl->value;
    obj["type"] = _impl->type;

    return obj;
}
