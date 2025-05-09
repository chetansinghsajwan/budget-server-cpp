cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project("budget-server" VERSION "0.1.0")
enable_language(CXX)

add_subdirectory("vendors/atom_core")
add_subdirectory("vendors/atom_logging")

add_executable(budget_server)

file(GLOB_RECURSE budget_server_modules "src/**.cppm")
file(GLOB_RECURSE budget_server_sources "src/**.cpp")

target_sources(budget_server PRIVATE FILE_SET CXX_MODULES FILES ${budget_server_modules})
target_sources(budget_server PRIVATE ${budget_server_sources})

target_link_libraries(budget_server PRIVATE atom_core)
target_link_libraries(budget_server PRIVATE atom_logging)
