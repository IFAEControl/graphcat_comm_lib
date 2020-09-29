#include <iostream>
#include <array>

#include "graphcat-lib.hpp"
#include "commands.hpp"
#include "sockets.hpp"

int readReg() {
    CommandCreator c;
    auto cmd = c.read_reg();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}


int GraphCATReset() {
    CommandCreator c;
    auto cmd = c.reset();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}

int ChipConfigRegisterWrite(const unsigned in[3], unsigned out[3]) {
    CommandCreator c;
    std::array<unsigned, 3> chip_config;
    for(int i = 0; i < 3; i++) chip_config[i] = in[i];
    auto cmd = c.write_chip_config(chip_config);
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}


int PixelPulseRegisterWrite(unsigned *pxPulseRegDatain[35], unsigned *pxPulseRegDataout[35]) {
    CommandCreator c;
    auto cmd = c.pixel_pulse_write();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}


int GeneratePulses() {
    CommandCreator c;
    auto cmd = c.generate_pulse();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}

int ReadTemperature(unsigned* temp) {
    if(!temp)
        return -1;
    
    CommandCreator c;
    auto cmd = c.read_temperature();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    *temp = resp.body["answer"]["temperature"];
    return 0;
}

void initCommunication(const char* str, unsigned sync_port, unsigned async_port) {
    set_dest_ip(str);
}


int gc_ping_pong() {
    CommandCreator c;
    auto cmd = c.ping_pong();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}
