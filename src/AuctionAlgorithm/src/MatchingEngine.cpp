
#include "MatchingEngine.hpp"

#include <fstream>
#include <string>
#include <vector>

// support only one Symbol
std::string MatchingEngine::fileName = "";

MatchingEngine::MatchingEngine() { orderBook = std::make_shared<OrderBook>(); }

void MatchingEngine::process(std::shared_ptr<Order>& order) { orderBook->match(order); }

void MatchingEngine::run() {
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile) {
        std::cout << "ok" << std::endl;
        std::string line;
        std::getline(inFile, line);
        const auto referencePrice = std::stod(line);
        orderBook->setReferencePrice(referencePrice);
        while (std::getline(inFile, line)) {
            auto anOrder = std::make_shared<Order>(line);
            std::cout << *anOrder << std::endl;
            process(anOrder);
            std::cout << "RT volume := " << orderBook->getVolume() << std::endl;
            std::cout << "RT emaining := " << orderBook->getRemaining() << std::endl;
        }
    } else {
        std::cout << "nok" << std::endl;
    }
}