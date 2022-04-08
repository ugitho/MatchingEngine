#include <iostream>

#include "AuctionAlgorithm/include/OrderBook.hpp"

int main() { 

    std::ifstream infile;
    infile.open("auctionData.txt");
    if(infile){
        std::cout << "ok" << std::endl;
    }
    else {
        std::cout << "nok"<< std::endl;
    }
    auto orderBook = std::make_shared<OrderBook>(infile);

    std::cout << "hello world" << std::endl; }