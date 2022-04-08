#pragma once
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

enum class OrderType { BUY, SELL };
using TimeStamps = std::string;
using Symbol = std::string;
using Quantity = std::uint64_t;
using Price = double;

class Order {
   public:
    Order(const std::string& orderFromLine);
    Order(const Order&) = delete;
    Order(const Order&&) = delete;
    Order& operator=(const Order&) = delete;
    Order& operator=(const Order&&) = delete;
    ~Order();

    const TimeStamps& getTimeStamps() const { return timeStamps; }
    const Symbol& getSymbol() const { return symbol; }
    const OrderType& getOrderType() const { return orderType; }
    const Quantity& getQuantity() const { return quantity; }
    const Price& getPrice() const { return price; }

    friend std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << "timeStamps := " << order.timeStamps << ", symbol := " << order.symbol
           << ", orderType := " << (order.orderType == OrderType::BUY ? "BUY" : "SELL")
           << ", quantity := " << order.quantity << ", price := " << order.price;
        return os;
    }
    // TODO use relative tolerance
    friend bool operator>(const Order& l, const Order& r) {
        if (l.orderType == OrderType::BUY) {
            if (std::fabs(l.price - r.price) < std::numeric_limits<double>::epsilon()) {
                return l.timeStamps < r.timeStamps;  // FIFO
            } else {
                return l.price > r.price;  // greater BID
            }
        } else {
            if (std::fabs(l.price - r.price) < std::numeric_limits<double>::epsilon()) {
                return l.timeStamps < r.timeStamps;  // FIFO
            } else {
                return l.price < r.price;  // lower ASK
            }
        }
    }

   private:
    TimeStamps timeStamps;
    Symbol symbol;
    OrderType orderType;
    Quantity quantity;
    Price price;
};
