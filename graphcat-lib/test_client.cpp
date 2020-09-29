#include <iostream>

#include "graphcat-lib.hpp"

int main() {
    initCommunication("172.16.17.90", 32000, 32001);
    /*unsigned temp = 0;
    ReadTemperature(&temp);
    std::cout << temp << std::endl;*/
    readReg();
}
