#pragma once

#include <string>
#include <memory>

class Order;
class OrderBook;

class MatchingEngineImpl {
   public:
    MatchingEngineImpl();
    MatchingEngineImpl(const MatchingEngineImpl&) = delete;
    MatchingEngineImpl(const MatchingEngineImpl&&) = delete;
    MatchingEngineImpl& operator=(const MatchingEngineImpl&) = delete;
    MatchingEngineImpl& operator=(const MatchingEngineImpl&&) = delete;
    ~MatchingEngineImpl(){}
    void run();
    void initEngine(const std::string& aFileName) { fileName = aFileName; }
    const std::shared_ptr<OrderBook>& getOrderBook() const { return orderBook; }

   private:
    void process(std::shared_ptr<Order>& order);
    std::shared_ptr<OrderBook> orderBook;
    std::string fileName;
};
