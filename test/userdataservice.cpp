#include "service/userdataservice.h"

#include <gtest/gtest.h>

TEST(UserDataService, Process)
{


    static constexpr std::array<const char*, 3> vals = {
        "VALOR1", "2", "VALOR3"
    };

    std::vector<Revenant::UserDataDesc> descs = {
        {"DATA1", Revenant::UserDataTypeEnum::STRING, []{return vals[0];}},
        {"DATA2", Revenant::UserDataTypeEnum::NUMBER, []{return vals[1];}},
        {"DATA3", Revenant::UserDataTypeEnum::STRING, []{return vals[2];}}
    };

    UserDataService service(descs);
    auto values = service.process();

    EXPECT_EQ(values.size(), descs.size());

    for (int i = 0; i < descs.size(); ++i)
    {
        EXPECT_EQ(values[i].name(), descs[i].name);
        EXPECT_EQ(values[i].type(), descs[i].type);
        EXPECT_EQ(values[i].value(), vals[i]);
    }



}