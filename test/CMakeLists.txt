
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable("${CMAKE_PROJECT_NAME}-test"
    rvector.cpp
)

target_link_libraries("${CMAKE_PROJECT_NAME}-test"
    PRIVATE
        GTest::gtest_main
        ${CMAKE_PROJECT_NAME}
)

include(GoogleTest)
gtest_discover_tests("${CMAKE_PROJECT_NAME}-test")