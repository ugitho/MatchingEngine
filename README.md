#1 This is a base structure for further cpp projects, assignments, ..

#2 Compile

mkdir build && cd build
cmake ..
make

#3 Unitest
./AuctionAlgorithmTest

#4 main
./main ../assets/auctionAAPL.txt

##
OrderBook contains 2 set of order.
1. buyOrders
2. sellOrders

##
Matching Engine reads the auction file line by line then process the order.
If any order is matched, the crosse price will be used to create an execution
If the order is not full fill, it will be add to the set to be prcocess later.

