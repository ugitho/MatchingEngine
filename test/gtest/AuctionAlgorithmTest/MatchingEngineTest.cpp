#include <gmock/gmock.h>

#include "MatchingEngineImpl.hpp"
#include "OrderBook.hpp"

TEST(MatchingEngineTest, TestMatchingEngineVolume) {
    std::string fileName("../assets/auctionAAPL.txt");
    auto engine = std::make_shared<MatchingEngineImpl>();
    engine->initEngine(fileName);
    engine->run();
    EXPECT_EQ(200, engine->getOrderBook()->getVolume());
}

TEST(MatchingEngineTest, TestMatchingEngineRemaining) {
    std::string fileName("../assets/auctionAAPL.txt");
    auto engine = std::make_shared<MatchingEngineImpl>();
    engine->initEngine(fileName);
    engine->run();
    EXPECT_EQ(-1500, engine->getOrderBook()->getRemaining());
}
