ecpg -o ./build/test_mod.c main.pgs 
cc -c ./build/test_mod.c -o ./build/test_mod.o
c++ -c main.cpp -o ./build/test_cpp.o
c++ ./build/test_cpp.o ./build/test_mod.o -lecpg -o ./build/test_cpp
./build/test_cpp
