ecpg -o ./build/test_mod.c main.pgs 
g++ -g -c main.cpp -o ./build/test_cpp.o
gcc -g -c ./build/test_mod.c -o ./build/test_mod.o
g++ -g ./build/test_cpp.o ./build/test_mod.o -lecpg -o ./build/test_cpp
./build/test_cpp
