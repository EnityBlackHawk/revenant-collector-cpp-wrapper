#include<gtest/gtest.h>

#include "descriptors.h"
#include "RVector.h"



TEST(RVector, InstanciateTest) {
    const RVector v = {1, 2, 3, 4, 5};
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
    EXPECT_EQ(v[3], 4);
    EXPECT_EQ(v[4], 5);
}

