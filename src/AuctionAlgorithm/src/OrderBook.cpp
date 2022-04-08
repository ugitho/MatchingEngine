
#include "OrderBook.hpp"

OrderBook::OrderBook(std::ifstream& inFile) {
    std::string line;
    std::getline(inFile, line);
    referencePrice = std::stod(line);
    std::cout << "referencePrice := " << referencePrice << std::endl;
    while (std::getline(inFile, line)) {
        auto anOrder = std::make_shared<Order>(line);
        // std::cout << *anOrder << std::endl;
        if (anOrder->getOrderType() == OrderType::BUY) {
            buyOrders.insert(anOrder);
        } else {
            sellOrders.insert(anOrder);
        }
    }
}

OrderBook::~OrderBook() {}