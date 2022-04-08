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

bool isEQ(const Price& lhs, const Price& rhs, const double precision = std::numeric_limits<double>::epsilon());
bool isLESS(const Price& lhs, const Price& rhs);
bool isGREAT(const Price& lhs, const Price& rhs);

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

    void setNewQuantity(const Quantity& newQuantity) { quantity = newQuantity; }
    friend std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << "timeStamps := " << order.timeStamps << ", symbol := " << order.symbol
           << ", orderType := " << (order.orderType == OrderType::BUY ? "BUY" : "SELL")
           << ", quantity := " << order.quantity << ", price := " << order.price;
        return os;
    }
    // TODO use relative tolerance
    friend bool operator<(const Order& lhs, const Order& rhs) {
        if (lhs.orderType == OrderType::BUY) {
            if (isEQ(lhs.price, rhs.price)) {
                return lhs.timeStamps > rhs.timeStamps;  // FIFO
            } else {
                return lhs.price > rhs.price;  // greater BID
            }
        } else {
            if (isEQ(lhs.price, rhs.price)) {
                return lhs.timeStamps > rhs.timeStamps;  // FIFO
            } else {
                return lhs.price < rhs.price;  // lower ASK
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
