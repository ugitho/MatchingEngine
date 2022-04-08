#include "Order.hpp"

Order::Order(const std::string& orderFromLine) {
    const std::string delimiter = ",";
    auto start = 0U;
    auto end = orderFromLine.find(delimiter);
    //    std::cout << "orderFromLine := " << orderFromLine << std::endl;
    timeStamps = orderFromLine.substr(start, end - start);
    start = end + delimiter.length();
    end = orderFromLine.find(delimiter, start);

    symbol = orderFromLine.substr(start, end - start);
    start = end + delimiter.length();
    end = orderFromLine.find(delimiter, start);

    orderType = (orderFromLine.substr(start, end - start) == "B" ? OrderType::BUY : OrderType::SELL);
    start = end + delimiter.length();
    end = orderFromLine.find(delimiter, start);

    quantity = std::stoi(orderFromLine.substr(start, end - start));
    start = end + delimiter.length();
    end = orderFromLine.find(delimiter, start);

    price = std::stod(orderFromLine.substr(start, end - start));
    if (std::fabs(price) < std::numeric_limits<double>::epsilon()) {
        if (orderType == OrderType::BUY) {
            price = std::numeric_limits<double>::max();
        }
    }
}

Order::~Order() {}