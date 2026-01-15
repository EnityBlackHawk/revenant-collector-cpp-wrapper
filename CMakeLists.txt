cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

option(REVENANT_ENABLE_TESTS "Enable tests for RevenantCollectorCpp" OFF)

project(RevenantCollectorCpp)

include(RevenantCollectorCppMacros.cmake)

include(FetchContent)
FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.5 # Optionally specify a commit hash, version tag or branch here
)
FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH "rust/Cargo.toml" CRATE_TYPES staticlib)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

add_library(RevenantCollectorCpp SHARED)
set_target_properties(RevenantCollectorCpp PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(RevenantCollectorCpp

        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern>
        $<INSTALL_INTERFACE:include>
)

file(GLOB_RECURSE REVENANT_COLLECTOR_PUBLIC_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/revenant-collector.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/model/*.h"
)

file(GLOB_RECURSE REVENANT_COLLECTOR_PRIVATE CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/extern/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/private/**/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(RevenantCollectorCpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
        ${REVENANT_COLLECTOR_PUBLIC_HEADERS}

        PRIVATE
        ${REVENANT_COLLECTOR_PRIVATE}
)
target_include_directories(RevenantCollectorCpp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_link_libraries(RevenantCollectorCpp PRIVATE revenant_collector nlohmann_json::nlohmann_json)

if(REVENANT_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

include(CMakePackageConfigHelpers)

configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/RevenantCollectorCppConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/RevenantCollectorCppConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RevenantCollectorCpp
)


include(GNUInstallDirs)
install(TARGETS RevenantCollectorCpp
        EXPORT RevenantCollectorCppTargets
        FILE_SET HEADERS
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/revenant
)
install(
        FILES RevenantCollectorCppMacros.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RevenantCollectorCpp
)
install(EXPORT RevenantCollectorCppTargets
        FILE RevenantCollectorCppConfig.cmake
        NAMESPACE RevenantCollectorCpp::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RevenantCollectorCpp
)
