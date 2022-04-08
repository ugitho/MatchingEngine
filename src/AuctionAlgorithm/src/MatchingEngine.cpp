
#include "MatchingEngine.hpp"

#include <fstream>
#include <string>
#include <vector>

// support only one Symbol
std::string MatchingEngine::fileName = "";

MatchingEngine::MatchingEngine() {
    std::ifstream infile;
    infile.open(fileName);
    if (infile) {
        std::cout << "ok" << std::endl;
        orderBook = std::make_shared<OrderBook>(infile);
        // std::cout << "Got an orderbook for this symbool" << std::endl;
    } else {
        std::cout << "nok" << std::endl;
    }
}

void MatchingEngine::process() {
    const auto& buyOrders = orderBook->getBuyOrders();
    for (auto& order : buyOrders) {
        std::cout << "order := " << *order << std::endl;
    }
    const auto& sellOrders = orderBook->getSellOrders();
    for (auto& order : sellOrders) {
        std::cout << "order := " << *order << std::endl;
    }
}