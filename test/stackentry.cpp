#include <gtest/gtest.h>
#include "revenant-collector.hpp"


TEST(StackEntry, CreateAndAccess)
{
    Revenant::StackEntry entry(
        std::string("FunctionName"),
        std::string("FileName.cpp"),
        std::string("42")
    );

    EXPECT_EQ(entry.name(), "FunctionName");
    EXPECT_EQ(entry.file(), "FileName.cpp");
    EXPECT_EQ(entry.line(), "42");
}