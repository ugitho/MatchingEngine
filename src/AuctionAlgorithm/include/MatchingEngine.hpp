#pragma once
#include <string>

class OrderBook;
class MatchingEngineImpl;

class MatchingEngine {
   public:
    static MatchingEngine& getInstance() {
        static MatchingEngine matchingEngine;
        return matchingEngine;
    }

    void initEngine(const std::string& aFileName);
    const std::shared_ptr<OrderBook>& getOrderBook() const;
    void run();

   private:
    MatchingEngine();    
    MatchingEngine(const MatchingEngine&) = delete;
    MatchingEngine(const MatchingEngine&&) = delete;
    MatchingEngine& operator=(const MatchingEngine&) = delete;
    MatchingEngine& operator=(const MatchingEngine&&) = delete;
    ~MatchingEngine(){}
    std::shared_ptr<MatchingEngineImpl> matchingEngineImpl;
};