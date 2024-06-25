cmake_minimum_required(VERSION 3.10)
project(JobSchedulerProject)

set(CMAKE_CXX_STANDARD 11)

# Find Boost components
find_package(Boost REQUIRED COMPONENTS system)

# Include Crow dependencies
include_directories(
    /usr/local/include
    ${Boost_INCLUDE_DIRS})

# Add source files
set(SOURCES
    src/main.cpp
    src/JobScheduler.cpp
    src/Job.cpp
    src/Logger.cpp
)

add_executable(JobScheduler ${SOURCES})

# Link necessary libraries
target_link_libraries(JobScheduler pthread)

