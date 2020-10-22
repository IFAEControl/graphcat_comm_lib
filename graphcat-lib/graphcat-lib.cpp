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


int GraphCATReset() try {
    CommandCreator c;
    auto cmd = c.reset();
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

int ChipConfigRegisterWrite(const unsigned in[3], unsigned out[3]) try {
    CommandCreator c;
    std::array<unsigned, 3> chip_config;
    for(int i = 0; i < 3; i++) chip_config[i] = in[i];
    auto cmd = c.write_chip_config(chip_config);
    auto resp = send_command(cmd);
    auto out_arr = resp.body["answer"]["chip_config"];
    std::copy(out_arr.begin(), out_arr.end(), out);
    std::cout << resp.body << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PixelConfigRegisterWrite(const unsigned in[560], unsigned out[560]) try {
    CommandCreator c;
    std::array<unsigned, 560> pixel_config;
    for(int i = 0; i < 560; i++) pixel_config[i] = in[i];
    auto cmd = c.write_pixel_config(pixel_config);
    auto resp = send_command(cmd);
    auto out_arr = resp.body["answer"]["pixel_config"];
    std::copy(out_arr.begin(), out_arr.end(), out);
    std::cout << resp.body << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PixelPulseRegisterWrite(const unsigned in[35], unsigned out[35]) try {
    CommandCreator c;
    std::array<unsigned, 35> pixel_pulse;
    for(int i = 0; i < 35; i++) pixel_pulse[i] = in[i];
    auto cmd = c.pixel_pulse_write(pixel_pulse);
    auto resp = send_command(cmd);
    auto out_arr = resp.body["answer"]["pixel_pulse"];
    std::copy(out_arr.begin(), out_arr.end(), out);
    std::cout << resp.body << std::endl;
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}


int GeneratePulses() try {
    CommandCreator c;
    auto cmd = c.generate_pulse();
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

int ReadTemperature(unsigned* temp) try {
    if(!temp)
        return -1;
    
    CommandCreator c;
    auto cmd = c.read_temperature();
    auto resp = send_command(cmd);
    std::cout << resp.m.body << std::endl;
    *temp = resp.getAnswer();
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

void initCommunication(const char* str, unsigned sync_port, unsigned async_port) {
    set_dest_ip(str);
}

int LnaHpfReset(unsigned wait_time_us) try {
    CommandCreator c;
    auto cmd = c.reset_lna_hpf(wait_time_us);
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

int LnaNeuronDriving(unsigned wait_time_us) try {
    CommandCreator c;
    auto cmd = c.lna_neuron_driving(wait_time_us);
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

int LnaNoNeuronDriving(unsigned wait_time_us) try {
    CommandCreator c;
    auto cmd = c.lna_no_neuron_driving(wait_time_us);
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

int PllOutResetStatus(unsigned* status) try {
    if(!status)
        return -1;
    
    CommandCreator c;
    auto cmd = c.get_pll_out_reset_status();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    *status = resp.body["answer"]["status"];
    return 0;
} catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
} catch(...) {
    std::cout << "F" << std::endl;
    return -2;
}

int PllBitStreamGenerator(unsigned mode) try {
    CommandCreator c;
    auto cmd = c.set_pll_bitstream_mode(mode);
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



int gc_ping_pong() {
    CommandCreator c;
    auto cmd = c.ping_pong();
    auto resp = send_command(cmd);
    std::cout << resp.body << std::endl;
    return 0;
}
