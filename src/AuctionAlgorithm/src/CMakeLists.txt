cmake_minimum_required(VERSION 3.10)

project(AuctionAlgorithm)

file(GLOB
     SOURCES
     "*.cpp"
     "*.h*")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(PROJECT_SRC
     Order.cpp
     OrderBook.cpp
     MatchingEngine.cpp
     Execution.cpp
     MatchingEngineImpl.cpp)

add_library(${PROJECT_NAME}
    ${PROJECT_SRC})