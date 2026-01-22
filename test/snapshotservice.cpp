#include <gtest/gtest.h>
#include "service/snapshotservice.h"

#include <fstream>

#include "model/snapshotconfigdesc.h"

TEST(SnapshotService, TakeSnapshot)
{

    SnapshotConfigDesc configDesc = {};
    configDesc.userData = { {"name", UserDataTypeEnum::STRING, []{return "NICE";}}} ;

    const SnapshotService snapshotService(configDesc);
    SnapshotResult result = snapshotService.takeSnapshot();

    if(result.result())
    {
        std::ifstream file(result.filePath());
        EXPECT_TRUE(file.is_open()) << "Snapshot file could not be opened: " << result.filePath();

    } else
    {
        FAIL() << "Snapshot creation failed, file path: " << result.filePath();
    }
}