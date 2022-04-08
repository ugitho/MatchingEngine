#pragma once

#include <fstream>
#include <memory>
#include <set>
#include <string>

#include "Order.hpp"
struct Comparaison {
    bool operator()(const std::shared_ptr<Order>& lhs, const std::shared_ptr<Order>& rhs) const {
        return *(lhs.get()) < *(rhs.get());
    }
};

using OrderSet = std::set<std::shared_ptr<Order>, Comparaison>;
using ReferencePrice = double;

class OrderBook {
   public:
    OrderBook(std::ifstream& inFile);
    OrderBook(const OrderBook&) = delete;
    OrderBook(const OrderBook&&) = delete;
    OrderBook& operator=(const OrderBook&) = delete;
    OrderBook& operator=(const OrderBook&&) = delete;
    ~OrderBook();
    const OrderSet& getBuyOrders() const { return buyOrders; }
    const OrderSet& getSellOrders() const { return sellOrders; }

   private:
    OrderSet buyOrders;
    OrderSet sellOrders;
    ReferencePrice referencePrice;
};