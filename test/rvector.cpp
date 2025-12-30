#include<gtest/gtest.h>

#include "descriptors.h"
#include "RVector.h"
#include "FFIExtractor.h"


TEST(RVector, InstanciateTest) {
    const RVector v = {1, 2, 3, 4, 5};
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 5);
}
TEST(RVector, InstanciateTestString) {
    const RVector<std::string> v = {"Enity", "Black", "Hawk"};
    EXPECT_STREQ(v[0].c_str(), "Enity");
    EXPECT_STREQ(v[1].c_str(), "Black");
    EXPECT_STREQ(v[2].c_str(), "Hawk");
    EXPECT_STREQ(v[3].c_str(), nullptr);
}

TEST(RVector, MoveSemantics)
{
    RVector<std::string> v = {"Enity", "Black", "Hawk"};
    const RVector<std::string> v2 = std::move(v);

    EXPECT_STREQ(v2[0].c_str(), "Enity");
    EXPECT_STREQ(v2[1].c_str(), "Black");
    EXPECT_STREQ(v2[2].c_str(), "Hawk");
    EXPECT_STREQ(v2[3].c_str(), nullptr);

}

TEST(RVector, FFIExtractor) {

    const RVector v = {1, 2, 3, 4, 5};
    ffi::RVector<char>& ffi = FFIExtractor::extractRVector(v);

    EXPECT_EQ(ffi.data, (char*) &v[0]);

}
