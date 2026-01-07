#include <gtest/gtest.h>
#include "service/snapshotservice.h"


TEST(SnapshotService, TakeSnapshot)
{
    SnapshotService snapshotService;
    bool result = snapshotService.takeSnapshot();
    EXPECT_TRUE(result);
}