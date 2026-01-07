#include <gtest/gtest.h>
#include "revenant-collector.hpp"

void Func2()
{
    Revenant::printStacktrace();
}

void Func1()
{
    Func2();
}

TEST(StackTrace, PrintStackTrace)
{
    Func1();
}

TEST(StackTrace, GetStackTrace)
{
    auto stack = Revenant::getStacktrace();
    EXPECT_FALSE(stack.empty());
}