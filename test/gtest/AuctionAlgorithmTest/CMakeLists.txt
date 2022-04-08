cmake_minimum_required(VERSION 3.10)
project(AuctionAlgorithmTest)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../src/AuctionAlgorithm/include)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../third-party/gtest/include)

set(PROJECT_SRC
    MatchingEngineTest.cpp)

add_executable(${PROJECT_NAME}
    ${PROJECT_SRC})

target_link_libraries(${PROJECT_NAME}
    -L${CMAKE_CURRENT_SOURCE_DIR}/../../../third-party/gtest/lib gtest gtest_main
    AuctionAlgorithm)
