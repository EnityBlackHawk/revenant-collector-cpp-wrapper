#pragma once

#include <nlohmann/json.hpp>
#include <string>

using JsonType = nlohmann::json;


class IJsonable
{
public:
	virtual JsonType toJson() const = 0;
	virtual std::string toDump() const {
		return toJson().dump();
	};
};