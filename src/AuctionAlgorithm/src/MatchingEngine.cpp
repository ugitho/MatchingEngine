
#include <string>
#include <vector>
#include "MatchingEngine.hpp"
#include <fstream>

// support only one Symbol
std::string MatchingEngine::fileName = "";

MatchingEngine::MatchingEngine(){
    std::ifstream infile;
    infile.open(fileName);
    if(infile){
        std::cout << "ok" << std::endl;
        orderBook = std::make_shared<OrderBook>(infile);
        std::cout << "Got an orderbook for this symbool" << std::endl; 
    }
    else {
        std::cout << "nok"<< std::endl;
    }
}


void MatchingEngine::process(){
    orderBook->getByOrders();
    orderBook->getSellOrders();
}