#include <iostream>
#include <array>
#include <algorithm>

#include "graphcat-lib.hpp"
#include "commands.hpp"
#include "sockets.hpp"

int readReg() try {
    CommandCreator c;
    auto cmd = c.read_reg();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
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
    auto out_arr = resp.body["answer"]["chip_config"];
    std::copy(out_arr.begin(), out_arr.end(), out);
    std::cout << resp.body << std::endl;
    return 0;
}

int PixelConfigRegisterWrite(const unsigned in[560], unsigned out[560]) {
    CommandCreator c;
    std::array<unsigned, 560> pixel_config;
    for(int i = 0; i < 560; i++) pixel_config[i] = in[i];
    auto cmd = c.write_pixel_config(pixel_config);
    auto resp = send_command(cmd);
    auto out_arr = resp.body["answer"]["pixel_config"];
    std::copy(out_arr.begin(), out_arr.end(), out);
    std::cout << resp.body << std::endl;
    return 0;
}

int PixelPulseRegisterWrite(const unsigned in[35], unsigned out[35]) {
    CommandCreator c;
    std::array<unsigned, 35> pixel_pulse;
    for(int i = 0; i < 35; i++) pixel_pulse[i] = in[i];
    auto cmd = c.pixel_pulse_write(pixel_pulse);
    auto resp = send_command(cmd);
    auto out_arr = resp.body["answer"]["pixel_pulse"];
    std::copy(out_arr.begin(), out_arr.end(), out);
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
