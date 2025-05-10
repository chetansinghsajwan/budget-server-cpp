cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project("budget-server" VERSION "0.1.0")
enable_language(CXX)

cmake_policy(SET CMP0077 NEW)

set(OpenSSL_DIR "/usr/local/lib64/cmake/OpenSSL")
find_package(OpenSSL 3.5.0 CONFIG REQUIRED)

add_subdirectory("vendors/atom_core")
add_subdirectory("vendors/atom_logging")

set(BUILD_SHARED_LIBS OFF)
set(PISTACHE_BUILD_TESTS OFF)
set(PISTACHE_ENABLE_FLAKY_TESTS OFF)
set(PISTACHE_ENABLE_NETWORK_TESTS OFF)
set(PISTACHE_USE_SSL ON)
set(PISTACHE_PIC ON)
set(PISTACHE_BUILD_FUZZ OFF)
add_subdirectory("vendors/pistache")

add_executable(budget_server)

file(GLOB_RECURSE budget_server_modules "src/*.cppm")
file(GLOB_RECURSE budget_server_sources "src/*.cpp" "src/*.cxx")

target_sources(budget_server PUBLIC FILE_SET CXX_MODULES FILES ${budget_server_modules})
target_sources(budget_server PUBLIC ${budget_server_sources})

target_link_libraries(budget_server PRIVATE "atom_core" "atom_logging" "pistache")
target_link_libraries(budget_server PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_compile_features(budget_server PRIVATE "cxx_std_23")
