#pragma once

#include <fstream>
#include <memory>
#include <set>
#include <string>

#include "Order.hpp"
using OrderSet = std::set<std::shared_ptr<Order>>;
using ReferencePrice = double;
class OrderBook {
   public:
    OrderBook(std::ifstream& inFile);
    OrderBook(const OrderBook&) = delete;
    OrderBook(const OrderBook&&) = delete;
    OrderBook& operator=(const OrderBook&) = delete;
    OrderBook& operator=(const OrderBook&&) = delete;
    ~OrderBook();
    const OrderSet& getByOrders() const { return buyOrders; }
    const OrderSet& getSellOrders() const { return sellOrders; }

   private:
    OrderSet buyOrders;
    OrderSet sellOrders;
    ReferencePrice referencePrice;
};