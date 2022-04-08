#1 This is a base structure for further cpp projects, assignments, ..

#2 Compile

mkdir build && cd build
cmake ..
make

#3 Format code

find ./src/ -iname *.h -o -iname *.cpp | xargs clang-format -i
find ./test/ -iname *.h -o -iname *.cpp | xargs clang-format -i
