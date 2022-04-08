#include <iostream>

#include "AuctionAlgorithm/include/MatchingEngine.hpp"

int main(int argc, char** argv) {
    if(argc <= 1) {
        std::cerr << "auction file not provided" << std::endl;
        return 1;
    }
    std::string fileName(argv[1]);
    MatchingEngine::getInstance().initEngine(fileName);
    std::clog << "starting engine" << std::endl;
    MatchingEngine::getInstance().run();
    std::clog << "stopping engine" << std::endl;
    return 0;
}