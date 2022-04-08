#pragma once

#include "OrderBook.hpp"

class MatchingEngine {
   public:
    static MatchingEngine& getInstance() {
        static MatchingEngine matchingEngine;
        return matchingEngine;
    }

    static void initEngine(const std::string& aFileName) { fileName = aFileName; }

    const std::shared_ptr<OrderBook>& getOrderBook() const { return orderBook; }

    void run();

   private:
    MatchingEngine();

    void process(std::shared_ptr<Order>& order);

    std::shared_ptr<OrderBook> orderBook;
    static std::string fileName;
};