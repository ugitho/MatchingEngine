#include <iostream>

#include "AuctionAlgorithm/include/MatchingEngine.hpp"

int main() {
    std::string fileName("auctionAAPL.txt");
    MatchingEngine::initEngine(fileName);
    MatchingEngine::getInstance().process();

    std::cout << "hello world" << std::endl; 
    
}