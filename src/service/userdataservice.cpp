#include "service/userdataservice.h"

#include <ranges>

UserDataService::UserDataService(const std::vector<Revenant::UserDataDesc>& descs) : _descs(descs)
{
}

std::vector<UserDataValue> UserDataService::process()
{
    auto values = _descs | std::views::transform([](const auto& desc) -> UserDataValue { return { desc.name, desc.collectorAction(), desc.type }; });
    return {values.begin(), values.end()};
}

