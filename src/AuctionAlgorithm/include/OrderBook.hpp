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
    OrderBook();
    OrderBook(const OrderBook&) = delete;
    OrderBook(const OrderBook&&) = delete;
    OrderBook& operator=(const OrderBook&) = delete;
    OrderBook& operator=(const OrderBook&&) = delete;
    ~OrderBook();
    const OrderSet& getBuyOrders() const { return buyOrders; }
    const OrderSet& getSellOrders() const { return sellOrders; }

    void match(const std::shared_ptr<Order>& order);
    void accumulateVolume(std::uint64_t executedVolume) { volume += executedVolume; }
    std::uint64_t getVolume() const { return volume; }
    std::int64_t getRemaining() const { return remaining; }
    void setReferencePrice(const ReferencePrice& referencePrice) { this->referencePrice = referencePrice; }

   private:
    OrderSet buyOrders;
    OrderSet sellOrders;
    ReferencePrice referencePrice;
    std::uint64_t volume;
    std::int64_t remaining;
};