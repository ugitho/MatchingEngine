
#include "OrderBook.hpp"

OrderBook::OrderBook() : volume(0), remaining(0) {}

OrderBook::~OrderBook() {}

void OrderBook::match(const std::shared_ptr<Order>& order) {
    std::clog << "matching order := " << *order << std::endl;
    if (order->getOrderType() == OrderType::BUY) {
        const auto& buyPrice = order->getPrice();
        for (auto sellOrder = sellOrders.begin(); sellOrder != sellOrders.end();) {
            std::clog << "sellOrder := " << *(*sellOrder) << std::endl;
            const auto& bestSellPrice = (*sellOrder)->getPrice();
            const auto& buyQuantity = order->getQuantity();
            const auto& sellQuantity = (*sellOrder)->getQuantity();

            std::clog << "buyQuantity := " << buyQuantity << std::endl;
            if (buyQuantity <= 0 || sellQuantity <= 0 || isGREAT(bestSellPrice, buyPrice)) {
                break;
            }
            auto matchedQuantiy = std::min(buyQuantity, sellQuantity);
            std::clog << "at price := " << bestSellPrice << ", executed := " << matchedQuantiy << std::endl;
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
            std::clog << "adding a buy order" << std::endl;
            remaining += order->getQuantity() ;
            buyOrders.insert(order);
        }
        std::clog << "finish buy order\n\n" << std::endl;
    } else {
        const auto& sellPrice = order->getPrice();
        for (auto buyOrder = buyOrders.begin(); buyOrder != buyOrders.end();) {
            std::clog << "buyOrder := " << *(*buyOrder) << std::endl;
            const auto& bestBuyPrice = (*buyOrder)->getPrice();
            const auto& sellQuantity = order->getQuantity();
            const auto& buyQuantity = (*buyOrder)->getQuantity();

            std::clog << "sellQuantity := " << sellQuantity << std::endl;
            if (sellQuantity <= 0 || buyQuantity <= 0 || isGREAT(sellPrice, bestBuyPrice)) {  // can't match any order
                break;
            }

            auto matchedQuantiy = std::min(buyQuantity, sellQuantity);
            std::clog << "at price := " << bestBuyPrice << ", executed := " << matchedQuantiy << std::endl;
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
            std::clog << "adding sell order" << std::endl;
            remaining -= order->getQuantity() ;
            sellOrders.insert(order);
        }
        std::clog << "finish sell order\n\n" << std::endl;
    }
}