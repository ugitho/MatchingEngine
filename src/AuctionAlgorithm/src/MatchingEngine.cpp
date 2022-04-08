#include "MatchingEngine.hpp"

#include "MatchingEngineImpl.hpp"
#include "OrderBook.hpp"

// support only one Symbol
MatchingEngine::MatchingEngine() { matchingEngineImpl = std::make_shared<MatchingEngineImpl>(); }

const std::shared_ptr<OrderBook>& MatchingEngine::getOrderBook() const { return matchingEngineImpl->getOrderBook(); }

void MatchingEngine::run() { matchingEngineImpl->run(); }

void MatchingEngine::initEngine(const std::string& aFileName) { matchingEngineImpl->initEngine(aFileName); }