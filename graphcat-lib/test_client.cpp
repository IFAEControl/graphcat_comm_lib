#include <iostream>

#include "graphcat-lib.hpp"

int main() {
    unsigned in[35];
    unsigned out[35];
    initCommunication("172.16.17.90", 32000, 32001);
    PixelPulseRegisterWrite(in, out);
    /*unsigned temp = 0;
    ReadTemperature(&temp);
    std::cout << temp << std::endl;*/
    //readReg();
}
