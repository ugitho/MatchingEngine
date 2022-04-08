#include "MatchingEngineImpl.hpp"

#include <fstream>

#include "OrderBook.hpp"

MatchingEngineImpl::MatchingEngineImpl() { orderBook = std::make_shared<OrderBook>(); }

void MatchingEngineImpl::process(std::shared_ptr<Order>& order) { orderBook->match(order); }

void MatchingEngineImpl::run() {
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile) {
        std::clog << "reading auction file" << std::endl;
        std::string line;
        std::getline(inFile, line);
        std::clog << "line := " << line << std::endl;
        const auto referencePrice = std::stod(line);
        orderBook->setReferencePrice(referencePrice);
        while (std::getline(inFile, line)) {
            auto order = std::make_shared<Order>(line);
            process(order);
        }
    } else {
        std::cerr << "error while opening auction file" << std::endl;
    }
}