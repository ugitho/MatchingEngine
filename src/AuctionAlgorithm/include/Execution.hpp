#pragma once

#include <string>

#include "Order.hpp"

class Execution {
   public:
    Execution();

   private:
    TimeStamps sellOrderTimeStamps;
    TimeStamps buyOrderTimeStamps;
    Quantity quantity;
    Price price;
};