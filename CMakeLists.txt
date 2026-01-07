cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

option(REVENANT_ENABLE_TESTS "Enable tests for RevenantCollectorCpp" ON)

project(RevenantCollectorCpp)

include(FetchContent)
FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.5 # Optionally specify a commit hash, version tag or branch here
)
FetchContent_MakeAvailable(Corrosion)


corrosion_import_crate(MANIFEST_PATH "rust/Cargo.toml" CRATE_TYPES staticlib)


add_library(${CMAKE_PROJECT_NAME} SHARED)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${CMAKE_PROJECT_NAME}

        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extern>
        $<INSTALL_INTERFACE:include>
)

target_sources(${CMAKE_PROJECT_NAME}

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
        include/revenant-collector.hpp
        include/stackentry.h

        PRIVATE
        extern/revenant-external.h
        src/revenant-collector.cpp
        src/stackentry.cpp
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE revenant_collector)

if(REVENANT_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
        EXPORT RevenantCollectorCppTargets
        FILE_SET HEADERS
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/revenant
)
install(EXPORT RevenantCollectorCppTargets
        FILE RevenantCollectorCppConfig.cmake
        NAMESPACE RevenantCollectorCpp::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/RevenantCollectorCpp
)