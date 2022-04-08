
#include "OrderBook.hpp"

OrderBook::OrderBook() : volume(0), remaining(0) {}

OrderBook::~OrderBook() {}

void OrderBook::match(const std::shared_ptr<Order>& order) {
    if (order->getOrderType() == OrderType::BUY) {
        const auto& buyPrice = order->getPrice();
        for (auto sellOrder = sellOrders.begin(); sellOrder != sellOrders.end();) {
            std::cout << "sellOrder := " << *(*sellOrder) << std::endl;
            const auto& bestSellPrice = (*sellOrder)->getPrice();
            const auto& buyQuantity = order->getQuantity();
            const auto& sellQuantity = (*sellOrder)->getQuantity();

            std::cout << "buyQuantity := " << buyQuantity << std::endl;
            if (buyQuantity <= 0 || sellQuantity <= 0 || isGREAT(bestSellPrice, buyPrice)) {
                break;
            }
            auto matchedQuantiy = std::min(buyQuantity, sellQuantity);
            std::cout << "at price := " << bestSellPrice << ", executed := " << matchedQuantiy << std::endl;
            accumulateVolume(matchedQuantiy);
            order->setNewQuantity(buyQuantity - matchedQuantiy);
            (*sellOrder)->setNewQuantity(sellQuantity - matchedQuantiy);
            if ((*sellOrder)->getQuantity() == 0) {
                sellOrders.erase(sellOrder++);
            } else {
                sellOrder++;
            }
        }
        if (order->getQuantity() > 0) {
            std::cout << "add buy order" << std::endl;
            remaining += order->getQuantity() ;
            buyOrders.insert(order);
        }
        std::cout << "finish buy order" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    } else {
        const auto& sellPrice = order->getPrice();
        for (auto buyOrder = buyOrders.begin(); buyOrder != buyOrders.end();) {
            std::cout << "buyOrder := " << *(*buyOrder) << std::endl;
            const auto& bestBuyPrice = (*buyOrder)->getPrice();
            const auto& sellQuantity = order->getQuantity();
            const auto& buyQuantity = (*buyOrder)->getQuantity();

            std::cout << "sellQuantity := " << sellQuantity << std::endl;
            if (sellQuantity <= 0 || buyQuantity <= 0 || isGREAT(sellPrice, bestBuyPrice)) {  // can't match any order
                break;
            }

            auto matchedQuantiy = std::min(buyQuantity, sellQuantity);
            std::cout << "at price := " << bestBuyPrice << ", executed := " << matchedQuantiy << std::endl;
            accumulateVolume(matchedQuantiy);
            order->setNewQuantity(sellQuantity - matchedQuantiy);
            (*buyOrder)->setNewQuantity(buyQuantity - matchedQuantiy);
            if ((*buyOrder)->getQuantity() == 0) {
                buyOrders.erase(buyOrder++);
            } else {
                buyOrder++;
            }
        }
        if (order->getQuantity() > 0) {
            std::cout << "add sell order" << std::endl;
            remaining -= order->getQuantity() ;
            sellOrders.insert(order);
        }
        std::cout << "finish sell order" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}